#include <stdio.h>

int total_time = 165;
char processes[2] = {'a', 'b'};
int periods[2] = {25, 35};
int bursts[2] = {50, 80};

typedef struct process_t {
  char *name;
  int period;
  int burst;
} process_t;

typedef struct node_t {
  process_t process;
  struct node_t *next;
} node_t;

int main(int argc, char *argv[]) {
  if (argc > 1) printf("%s\n", argv[1]);

  // check priority
  // sort a linked list by priority

  return 0;
}