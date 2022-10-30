#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NP 1000

int num_processes = 0;
int exec_index = 0;

typedef struct process_st {
  char name[10];
  int period;
  int burst;
  int remaining_burst;
  char status;
} process_st;

typedef struct log_st {
  char name[10];
  int runtime;
  char status;
} log_st;

void swapProcesses(process_st *processes, int pos1) {
  process_st temp = processes[pos1];
  processes[pos1] = processes[pos1 - 1];
  processes[pos1 - 1] = temp;
}

void sortByPriority(process_st *processes) {
  for (int i = num_processes - 1; i >= exec_index; i--) {
    for (int j = num_processes - 1; j > exec_index; j--) {
      if (processes[j - 1].period > processes[j].period) {
        swapProcesses(processes, j);
      }
    }
  }
}

void insertProcessToList(process_st *processes, process_st process) {
  process_st new_process;
  new_process.burst = process.burst;
  new_process.period = process.period;
  strcpy(new_process.name, process.name);
  new_process.remaining_burst = process.burst + 1;
  processes[num_processes] = new_process;
  num_processes++;
  sortByPriority(processes);
}

void printList(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    printf("%s %d %d %d\n", processes[i].name, processes[i].period, processes[i].burst, processes[i].remaining_burst);
  }
  printf("==========\n\n");
}

int checkAndInsertIncomingProcess(process_st *processes, int elapsed_time) {
  for (int i = 0; i < num_processes; i ++) {
    if (elapsed_time % processes[i].period == 0) {
      process_st incoming = processes[i];
      insertProcessToList(processes, incoming);
      return 1;
    }
  }
  return 0;
}

void logProcessState(log_st *logs, process_st process, int log_index, int interval) {
  logs[log_index].status = process.status;
  strcpy(logs[log_index].name, process.name);
  logs[log_index].runtime = interval;
}

void printLogs(log_st *logs, int log_index) {
  for (int i = 0; i < log_index; i ++) {
    if (!strcmp(logs[i].name, "IDLE")) {
      printf("idle for %d units\n", logs[i].runtime);
    }
    else {
      printf("[%s] for %d units - %c\n", logs[i].name, logs[i].runtime, logs[i].status);
    }
  }
}

void killRemainingProcesses(process_st *processes, int exec_index, log_st *logs, int log_index, int interval) {
  for (int i = exec_index; i < num_processes; i++) {

    processes[i].status = 'K';  // Killed
    logProcessState(logs, processes[i], log_index, interval);
  }
}

int main(int argc, char *argv[]) {
  if (argc > 1) printf("%s\n\n", argv[1]);

  // mock time
  int total_time = 165;

  process_st processes[NP];
  // process_st preempted[NP];
  log_st logs[NP];

  // mock processes
  process_st mock_process1;
  mock_process1.burst = 25;
  mock_process1.period = 50;
  strcpy(mock_process1.name, "t1");
  mock_process1.remaining_burst = mock_process1.burst + 1;
  insertProcessToList(processes, mock_process1);

  process_st mock_process2;
  mock_process2.burst = 35;
  mock_process2.period = 80;
  strcpy(mock_process2.name, "t2");
  mock_process2.remaining_burst = mock_process2.burst + 1;
  insertProcessToList(processes, mock_process2);

  // process_st mock_process3;
  // mock_process3.burst = 15;
  // mock_process3.period = 50;
  // strcpy(mock_process3.name, "t3");
  // mock_process3.remaining_burst = mock_process3.burst;
  // insertProcessToList(processes, mock_process3);

  printList(processes);

  int elapsed_time = 0;
  int interval = 0;

  int last_finished_index;

  int log_index = 0;

  process_st running;
  // && exec_index < num_processes
  while (elapsed_time <= total_time && exec_index < num_processes) {
    // if (exec_index < num_processes ) {
    //   process_st idle;
    //   strcpy(idle.name, "IDLE");
    //   logProcessState(logs, idle, log_index, interval);
    //   interval = 0;

    // }
    running = processes[exec_index];

    if (processes[exec_index].remaining_burst == 0) {  // processes[exec_index].remaining_burst == 0 || interval >= processes[exec_index].burst
      processes[exec_index].status = 'F';  // Finished
      last_finished_index = exec_index;
      processes[exec_index].remaining_burst = processes[exec_index].burst - interval;
      logProcessState(logs, processes[exec_index], log_index, interval);
      log_index++;
      interval = 0;
      exec_index++;
    }
    else if (elapsed_time > 0 && checkAndInsertIncomingProcess(processes, elapsed_time)) {

      if (running.period > processes[exec_index].period) {
        running.status = 'H';  // Halted
        processes[exec_index].remaining_burst = processes[exec_index].burst - interval;
        logProcessState(logs, running, log_index, interval);
        log_index++;
        interval = 0;
      }
      else if (!strcmp(running.name, processes[exec_index].name)) {
        running.status = 'L';  //Lost
        processes[exec_index].remaining_burst = processes[exec_index].burst - interval;
        logProcessState(logs, running, log_index, interval);
        log_index++;
        exec_index++;
        interval = 0;
      }
    }
    else {
      processes[exec_index].status = 'R';  // Running
      processes[exec_index].remaining_burst--;
      
      printf("momento: %d\n", elapsed_time);
      printf("index: %d\n", exec_index);
      printList(processes);

      interval++;
      elapsed_time++;
    }
  }

  // killRemainingProcesses(processes, last_finished_index, logs, log_index, interval);

  printf("EXECUTION BY RATE\n");
  printLogs(logs, log_index);

  return 0;
}