#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REALLY_BIG_NUM 1000

typedef struct process_st {
  char name[REALLY_BIG_NUM];
  int period;
  int burst;
  int elapsed_burst;
  char status;
} process_st;

typedef struct log_st {
  char proc_name[REALLY_BIG_NUM];
  char status;
  int units;
} log_st;

int num_processes = 0;
int exec_index = 0;
int log_index = 0;
int total_time = 0;
int is_running = 1;
int interval = 0;

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
    count ++;
  }

  return count;
}

void logProcess(process_st process, log_st *logs, int interval) {
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
      if (!strcmp(init_processes[i].name, processes[j].name) && (processes[j].status == 'W' || processes[j].status == 'K' || processes[j].status == 'H')) {
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

void printList(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    printf("%s %d %d %d - %c\n", processes[i].name, processes[i].period, processes[i].burst, processes[i].elapsed_burst, processes[i].status);
  }
  printf("==========\n\n");
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
          logProcess(*running, logs, interval);
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

void killRemainingProcesses(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    if (processes[i].status == 'W' || processes[i].status == 'R') {
      processes[i].status = 'K';
    }
  }
}

int main(int argc, char **argv) {
  if (argc > 2) {
    fprintf(stderr, "Wrong number of arguments passed to ./rate [file name]. Expected 1 received %d\n", argc - 1);
    exit(EXIT_FAILURE);
  }
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "File '%s' not found.\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  int count = getProcessCount(file);
  fclose(file);
  process_st first_come[count];

  process_st processes[REALLY_BIG_NUM];
  log_st logs[REALLY_BIG_NUM];

  file = fopen(argv[1], "r");
  getInputFile(file, first_come, processes);
  sortProcessesByPriority(processes);

  int elapsed_time = 0;
  int checked = 0;

  while (elapsed_time < total_time) {
    if (exec_index >= num_processes) {
      is_running = 0;
    }
    if (is_running) {
      process_st *running = &processes[exec_index];
      process_st running_copy = processes[exec_index];

      if (running->elapsed_burst < running->burst) {
        if (running->status == 'L') {  // skip if process is lost
          exec_index++;
          running = &processes[exec_index];
          interval = 0;
        }
        else if (checked == 0) {  // this variable fixes a logic hole that causes an incoming process to be inserted twice after coming back from idle state
          process_st copy = *running;
          if (elapsed_time > 0 && checkAndInsert(running, first_come, processes, elapsed_time, count, logs)) {
            // printf("NEW PROCESS ARRIVED!\n");
          }
        }
        if (running->status == 'L') {  // skip if process is lost
          exec_index++;
          running = &processes[exec_index];
          interval = 0;
        }
        running->status = 'R';
        elapsed_time ++;
        interval ++;
        running->elapsed_burst ++;
      }
      else {
        running->status = 'F';
        logProcess(*running, logs, interval);
        exec_index++;
        interval = 0;
      }
      checked = 0;

      if (elapsed_time == total_time && running->elapsed_burst < running->burst) {
        running->status = 'K';
        logProcess(*running, logs, interval);
      }
      else if (elapsed_time == total_time && running->elapsed_burst == running->burst){
        running->status = 'F';
        logProcess(*running, logs, interval);
      }

      // printf("time: %d\n", elapsed_time);
      // printf("interval: %d\n", interval);
      // printf("index: %d\n", exec_index);
      // printList(processes);
    }
    else {
      int response = checkAndInsert(NULL, first_come, processes, elapsed_time, count, logs);
      if (response) {
        checked = 1;
        is_running = 1;
        process_st idle;
        strcpy(idle.name, "IDLE");
        logProcess(idle, logs, interval);
        interval = 0;
      }
      else {
        elapsed_time++;
        interval++;
      }
    }
  }

  // printf("FINAL\n");
  // printList(processes);

  printLogs(logs, first_come, processes, count);

  exit(EXIT_SUCCESS);
}