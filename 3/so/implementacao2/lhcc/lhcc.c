#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils/utils.h"

int num_processes = 0;
int exec_index = 0;
int log_index = 0;
int total_time = 0;
int is_running = 1;
int interval = 0;

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

  while (elapsed_time <= total_time) {
    if (exec_index >= num_processes) {
      is_running = 0;
    }
    if (is_running) {
      process_st *running = &processes[exec_index];

      if (running->elapsed_burst < running->burst) {
        if (checked == 0 && elapsed_time > 0) {  // this variable fixes a logic hole that causes an incoming process to be inserted twice after coming back from idle state
          checkAndInsert(running, first_come, processes, elapsed_time, count, logs);
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
    }
    else {
      int response = checkAndInsert(NULL, first_come, processes, elapsed_time, count, logs);

      if (response || elapsed_time == total_time) {
        checked = 1;
        is_running = 1;
        process_st idle;
        strcpy(idle.name, "IDLE");
        if (interval > 0) logProcess(idle, logs, interval);
        interval = 0;
      }
      else {
        elapsed_time++;
        interval++;
      }
    }
  }

  printLogs(logs, first_come, processes, count);

  exit(EXIT_SUCCESS);
}