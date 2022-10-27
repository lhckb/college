#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NP 2

typedef struct process_st {
  char name[10];
  int period;
  int burst;
  int remaining_burst;
  char status;
  struct process_st *next;
} process_st;

void freeAll(process_st *head) {
  process_st *curr = head;
  process_st *next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  // free(curr);
  free(next);
}

void insertNewNode(process_st *head, int burst, int period, char *name) {
  process_st *curr = head;
  process_st *new = (process_st *) malloc(sizeof(process_st));
  for (curr = head; curr->next != NULL; curr = curr->next);
  curr->next = new;
  new->burst = burst;
  new->period = period;
  strcpy(new->name, name);
  new->next = NULL;
}

void printLinkedList(process_st *head) {
  process_st *curr;
  for (curr = head->next; curr != NULL; curr = curr->next) {
    printf("%s %d %d\n", curr->name, curr->period, curr->burst);
  }
  printf("==========\n");
}

int main(int argc, char *argv[]) {
  if (argc > 1) printf("%s\n", argv[1]);

  // mock time
  int total_time = 165;

  process_st *head = (process_st *) malloc(sizeof(process_st));
  head->next = NULL;

  // mock process 0
  insertNewNode(head, 25, 50, "t0");

  // mock process 1
  insertNewNode(head, 35, 80, "t1");

  printLinkedList(head);

  int processes_finished[NP];  // each index representes a process
  int processes_lost[NP]; 
  int processes_killed[NP]; 

  int elapsed_time = 0;
  int interval = 0;

  while (elapsed_time < total_time) {
    //...

    elapsed_time++;
  }

  // freeAll(head);

  return 0;
}