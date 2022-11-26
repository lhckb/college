#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define REALLY_BIG_NUM 1000

extern int num_processes;
extern int exec_index;
extern int log_index;
extern int total_time;
extern int is_running;
extern int interval;

void createProcess(char *line, process_st *first_come, process_st *processes) {
  char *process[3];
  int index = 0;
  char *slice;
  int true = 1;

  process_st new_process;

  for (int i = 0; i < strlen(line); i++) {
    if (line[i] == '\n') {
      line[i] = '\0';
    }
  }

  index = 0;

  while(true) {
    slice = strtok_r(line, " ", &line);
    if (slice != NULL) {
      process[index] = slice;
      index++;
    }
    else {
      if (index != 3) {
        fprintf(stderr, "File format not as specified.\n");
        exit(EXIT_FAILURE);
      }
      true = 0;
    }
  }

  strcpy(new_process.name, process[0]);
  new_process.period = atoi(process[1]);
  new_process.burst = atoi(process[2]);
  new_process.elapsed_burst = 0;
  new_process.status = 'W';

  first_come[num_processes] = new_process;
  processes[num_processes] = new_process;
  num_processes++;
}

void getInputFile(FILE *input, process_st *first_come, process_st *processes) {
  char *buffer;
  size_t length = 0;
  int count = 0;

  while (getline(&buffer, &length, input) != -1) {
    if (count == 0) {
      total_time = atoi(buffer);
    }
    else {
      createProcess(buffer, first_come, processes);
    }
    count ++;
  }
}

int getProcessCount(FILE *input) {
  char *buffer;
  size_t length = 0;
  int count = -1;  // starts on -1 to account for cpu time which is the first line

  while (getline(&buffer, &length, input) != -1) {
    if (!strcmp(buffer, "\n")) {
        fprintf(stderr, "File format not as specified.\n");
        exit(EXIT_FAILURE);
    }
    count ++;
  }

  return count;
}

void logProcess(process_st process, log_st *logs, int interval) {
  printf("LOGGING... %s - %d - %c\n", process.name, interval, process.status);
  strcpy(logs[log_index].proc_name, process.name);
  logs[log_index].status = process.status;
  logs[log_index].units = interval;
  log_index++;
}

void printLogs(log_st *logs, process_st *init_processes, process_st *processes, int count) {
  FILE *output = fopen("rate_lhcc.out", "w");
  if (output == NULL) {
    fprintf(stderr, "Could not write to output file.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(output, "EXECUTION BY RATE\n");

  for (int i = 0; i < log_index; i ++) {
    if (!strcmp(logs[i].proc_name, "IDLE")) {
      fprintf(output, "idle for %d units\n", logs[i].units);
    }
    else {
      fprintf(output, "[%s] for %d units - %c\n", logs[i].proc_name, logs[i].units, logs[i].status);
    }
  }

  int losts[count];
  int completed[count];
  int killed[count];

  for (int i = 0; i < count; i++) {
    losts[i] = 0;
    completed[i] = 0;
    
    for (int j = 0; j <= log_index; j++) {
      if (!strcmp(init_processes[i].name, processes[j].name) && processes[j].status == 'L') {
        losts[i] ++;
      }
      if (!strcmp(init_processes[i].name, logs[j].proc_name) && logs[j].status == 'F') {
        completed[i] ++;
      }
    }
  }

  fprintf(output, "\nLOST DEADLINES\n");
  for (int i = 0; i < count; i++) {
    fprintf(output, "[%s] %d\n", init_processes[i].name, losts[i]);
  }
  
  fprintf(output, "\nCOMPLETE EXECUTION\n");
  for (int i = 0; i < count; i++) {
    fprintf(output, "[%s] %d\n", init_processes[i].name, completed[i]);
  }

  for (int i = 0; i < count; i++) {
    killed[i] = 0;

    for (int j = 0; j < num_processes; j++) {
      if (!strcmp(init_processes[i].name, processes[j].name) && (processes[j].status == 'W' || processes[j].status == 'K' || processes[j].status == 'H' || processes[j].status == 'R')) {
        killed[i] ++;
      }
    }
  }

  fprintf(output, "\nKILLED\n");
  for (int i = 0; i < count; i++) {
    fprintf(output, "[%s] %d", init_processes[i].name, killed[i]);
    if (i != count - 1) fprintf(output, "\n");
  }
}

void swapProcesses(process_st *processes, int pos1) {
  process_st temp = processes[pos1];
  processes[pos1] = processes[pos1 + 1];
  processes[pos1 + 1] = temp;
}

void sortProcessesByPriority(process_st *processes) {
  for (int i = num_processes - 1; i >= exec_index; i--) {
    for (int j = num_processes - 1; j > exec_index; j--) {
      if (processes[j - 1].period > processes[j].period) {
        swapProcesses(processes, j - 1);
      }
    }
  }
}

int checkInstanceOfSame(process_st process, process_st *processes, log_st *logs) {
  int validation = 0;

  for (int i = 0; i < num_processes; i++) {
    if (!strcmp(processes[i].name, process.name) && processes[i].status != 'F') {
      processes[i].status = 'L';
      validation++;
    }
  }

  if (validation > 0) return 1;
  return 0;
}

int checkAndInsert(process_st *running, process_st *first_come, process_st *processes, int time, int count, log_st *logs) {
  int process_did_arrive = 0;
  process_st new_process;
  for (int i = 0; i < count; i++) {
    if (time % first_come[i].period == 0) {
      if (is_running) {
        if (first_come[i].period < running->period) {
          running->status = 'H';
          if (interval > 0) logProcess(*running, logs, interval);
          interval = 0;
        } 
        if (checkInstanceOfSame(first_come[i], processes, logs) && !strcmp(running->name, first_come[i].name)) {
          if (interval > 0) logProcess(*running, logs, interval);
        }
      }
      new_process.burst = first_come[i].burst;
      new_process.elapsed_burst = 0;
      strcpy(new_process.name, first_come[i].name);
      new_process.period = first_come[i].period;
      new_process.status = 'W';
      processes[num_processes] = new_process;
      num_processes++;
      process_did_arrive++;
    }
  }
  if (process_did_arrive > 0) {
    sortProcessesByPriority(processes);
    return 1;
  }
  return 0;
}

void printList(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    printf("%s %d %d %c\n", processes[i].name, processes[i].burst, processes[i].elapsed_burst, processes[i].status);
  }
}
