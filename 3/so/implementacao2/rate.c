#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM 1000

typedef struct process_st {
  char name[10];
  int period;
  int burst;
  int elapsed_burst;
  char status;
} process_st;

typedef struct log_st {
  char proc_name[10];
  char status;
  int units;
} log_st;

int num_processes = 0;
int exec_index = 0;
int log_index = 0;
int total_time = 0;
int is_running = 1;

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
  printf("LOGGING... %s %d %c\n", process.name, interval, process.status);
  strcpy(logs[log_index].proc_name, process.name);
  logs[log_index].status = process.status;
  logs[log_index].units = interval;
  log_index++;
}

void printLogs(log_st *logs, process_st *init_processes, process_st *processes, int count) {
  for (int i = 0; i < log_index; i ++) {
    if (!strcmp(logs[i].proc_name, "IDLE")) {
      printf("idle for %d units\n", logs[i].units);
    }
    else {
      printf("[%s] for %d units - %c\n", logs[i].proc_name, logs[i].units, logs[i].status);
    }
  }

  int losts[count];
  int completed[count];
  int killed[count];
  for (int i = 0; i < count; i++) {
    losts[i] = 0;
    completed[i] = 0;
    
    for (int j = 0; j <= log_index; j++) {
      if (!strcmp(init_processes[i].name, logs[j].proc_name) && logs[j].status == 'L') {
        losts[i] ++;
      }
      if (!strcmp(init_processes[i].name, logs[j].proc_name) && logs[j].status == 'F') {
        completed[i] ++;
      }
    }
  }
  printf("\nLOST DEADLINES\n");
  for (int i = 0; i < count; i++) {
    printf("[%s] %d\n", init_processes[i].name, losts[i]);
  }
  
  printf("\nCOMPLETE EXECUTION\n");
  for (int i = 0; i < count; i++) {
    printf("[%s] %d\n", init_processes[i].name, completed[i]);
  }

  for (int i = 0; i < count; i++) {
    killed[i] = 0;

    for (int j = 0; j < num_processes; j++) {
      if (!strcmp(init_processes[i].name, processes[j].name) && (processes[j].status == 'W' || processes[j].status == 'K')) {
        killed[i] ++;
      }
    }
  }

  printf("\nKILLED\n");
  for (int i = 0; i < count; i++) {
    printf("[%s] %d\n", init_processes[i].name, killed[i]);
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

int checkInstanceOfSame(process_st process, process_st *processes, int interval, log_st *logs) {
  printf("NUM PROCESSES AQUI %d\n", num_processes);
  int validation = 0;
  // printList(processes);
  for (int i = 0; i < num_processes; i++) {
    // printf("%d\n", i);
    if (!strcmp(processes[i].name, process.name) && processes[i].status != 'F') {
      processes[i].status = 'L';
      printf("%s %d %d %d - %c\n", processes[i].name, processes[i].period, processes[i].burst, processes[i].elapsed_burst, processes[i].status);

      validation++;
    }
  }

  if (validation > 0) return 1;
  return 0;
}

int checkAndInsert(process_st *running, process_st *first_come, process_st *processes, int time, int count, int interval, log_st *logs) {
  int process_did_arrive = 0;
  process_st new_process;
  for (int i = 0; i < count; i++) {
    if (time % first_come[i].period == 0) {
      if (is_running) {
        if (first_come[i].period < running->period) {
          running->status = 'H';
        } 
        if (checkInstanceOfSame(first_come[i], processes, interval, logs)) {
          // exec_index++;
          // running = &processes[exec_index];
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
    // num_processes += process_did_arrive;
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
    return 1;
  }
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "File '%s' not found.\n", argv[1]);
    return 1;
  }

  int count = getProcessCount(file);
  fclose(file);
  process_st first_come[count];

  process_st processes[MAX_NUM];
  log_st logs[MAX_NUM];

  file = fopen(argv[1], "r");
  getInputFile(file, first_come, processes);
  sortProcessesByPriority(processes);

  int elapsed_time = 0;
  int interval = 0;
  int checked = 0;

  while (elapsed_time < total_time) {
    if (exec_index >= num_processes) {
      is_running = 0;
    }
    if (is_running) {
      process_st *running = &processes[exec_index];
      process_st running_copy = processes[exec_index];
      // running->status = 'H';

      if (running->elapsed_burst < running->burst) {  // there is still burst left
        if (running->status == 'L') {  // process is lost
          exec_index++;
          running = &processes[exec_index];
          interval = 0;
        }
        else if (checked == 0) {  // this variable fixes a bug that causes an incoming process to be inserted twice after coming back from idle state
          process_st copy = *running;
          if (elapsed_time > 0 && checkAndInsert(running, first_come, processes, elapsed_time, count, interval, logs)) {
            printf("NEW PROCESS ARRIVED!\n");
            // if (strcmp(running->name, copy.name) || running->elapsed_burst != copy.elapsed_burst) {  // make sure it logs only when the current running process is preempted
            //   // logProcess(copy, logs, interval);
            //   interval = 0;
            // } 
          }
        }
        if (running->status == 'L') {  // process is lost
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
        // logProcess(*running, logs, interval);
        exec_index++;
        interval = 0;
      }
      checked = 0;

      if (elapsed_time == total_time && running->elapsed_burst < running->burst) {
        running->status = 'K';
        // logProcess(*running, logs, interval);
      }
      else if (elapsed_time == total_time && running->elapsed_burst == running->burst){
        running->status = 'F';
      }

      printf("time: %d\n", elapsed_time);
      printf("interval: %d\n", interval);
      printf("index: %d\n", exec_index);
      printList(processes);
    }
    else {
      int response = checkAndInsert(NULL, first_come, processes, elapsed_time, count, interval, logs);
      // printf("time: %d\n", elapsed_time);
      if (response) {
        checked = 1;
        is_running = 1;
        process_st idle;
        strcpy(idle.name, "IDLE");
        // logProcess(idle, logs, interval);
        interval = 0;
      }
      else {
        elapsed_time++;
        interval++;
      }
    }
  }

  printf("FINAL\n");
  printList(processes);

  // printf("EXECUTION BY RATE\n");
  // printLogs(logs, first_come, processes, count);

  return 0;
}