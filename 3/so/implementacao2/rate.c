#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NP 2

int num_processes = 0;

typedef struct process_st {
  char name[10];
  int period;
  int burst;
  int remaining_burst;
  char status;
  struct process_st *next;
} process_st;

void insertProcessToList(process_st *processes, int burst, int period, char *name) {
  process_st new_process;
  new_process.burst = burst;
  new_process.period = period;
  strcpy(new_process.name, name);
  processes[num_processes] = new_process;
  num_processes++;
}

void printList(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    printf("%s %d %d\n", processes[i].name, processes[i].period, processes[i].burst);
  }
  printf("==========\n\n");
}

void sortByPriority(process_st *processes) {
  for (int i = 0; i < num_processes; i++) {
    for (int j = 0; j < num_processes - 1; j++) {
      if (processes[j].period > processes[j + 1].period) {
        process_st temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc > 1) printf("%s\n\n", argv[1]);

  // mock time
  int total_time = 165;

  process_st processes[NP];

  // mock processes
  insertProcessToList(processes, 25, 50, "t0");
  insertProcessToList(processes, 35, 20, "t1");

  sortByPriority(processes);

  // printList(processes);

  int processes_finished[NP];  // each index representes a process
  int processes_lost[NP]; 
  int processes_killed[NP]; 

  int elapsed_time = 0;
  int interval = 0;

  while (elapsed_time < total_time) {
    //...
    

    elapsed_time++;
  }

  return 0;
}