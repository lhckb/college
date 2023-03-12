#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define REALLY_BIG_NUM 1000

extern process_st null_space;
extern int max;
int hole_index = 0;

int isNullSpace(process_st *memory, int index) {
  if (!strcmp(memory[index].name, "NULL")) {
    return 1;
  }
  return 0;
}

void removeNewLine(char *line) {
  if (line[strlen(line) - 1] == '\n') {
    line[strlen(line) - 1] = '\0';
  }
}

void printHoleArray(hole_st *holes) {
  for (int i = 0; i < hole_index; i++) {
    printf("Hole starting at %d with size %d\n", holes[i].start_position, holes[i].size);
  }
}

void updateHoleArray(hole_st *holes, process_st* memory) {
  hole_index = 0;
  int count;
  for (int i = 0; i < max;) {
    int start_index = i;
    count = 0;
    if (isNullSpace(memory, i)) {
      while (isNullSpace(memory, i)) {
        count++;
        i++;
      }
      holes[hole_index].start_position = start_index;
      holes[hole_index].size = count;
      hole_index++;
    }
    else { i++; }
  }
}

void initMemory(process_st *memory) {
  for (int i = 0; i < max; i++) {
    memory[i] = null_space;
  }
}

void printMemoryStatus(process_st *memory, FILE *output) {
  for (int i = 0; i < max; ) {
    if (isNullSpace(memory, i)) {
      int start_position = i;
      while (!strcmp(memory[i].name, null_space.name)) {
        i++;
      }
      int end_position = i - 1;

      fprintf(output, "Addresses [%d:%d] Unused\n", start_position, end_position);
    }
    else {
      int start_position = i;
      char process_name[BIG_NUM];
      strcpy(process_name, memory[i].name);

      while (!strcmp(memory[i].name, process_name)) {
        i++;
      }
      int end_position = i - 1;

      fprintf(output, "Addresses [%d:%d] %s\n", start_position, end_position, process_name);
    }
  }

}

void releaseMemorySpace(char *command[4], process_st *memory, hole_st *holes, FILE *output) {
  char process_name[BIG_NUM];
  strcpy(process_name, command[1]);
  int valid = 0;

  for (int i = 0; i < max; i++) {
    if (!strcmp(memory[i].name, process_name)) {
      memory[i] = null_space;
      valid = 1;
    }
  }

  updateHoleArray(holes, memory);

  if (!valid) {
    fprintf(output, "Fail to release %s\n", process_name);
  }
  else {
    fprintf(output, "Release %s\n", process_name);
  }
  
}

void allocateWorstFit(process_st* memory, char *command[4], hole_st *holes, FILE *output) {
  long int requested = atoi(command[2]);
  hole_st best_hole = holes[0];
  int valid = 0;
  for (int i = 1; i < hole_index; i++) {
    if (holes[i].size > best_hole.size) {
      best_hole = holes[i];
      valid = 1;
    }
  }

  if (best_hole.size >= requested && (best_hole.start_position + best_hole.size) <= max) {  // allocate if true
    for (int i = best_hole.start_position; i < requested + best_hole.start_position; i++) {
      strcpy(memory[i].name, command[1]);
      memory[i].requested = requested;
      memory[i].start_idx = best_hole.start_position;
    }
    fprintf(output, "Allocate %s to %s with Worst Fit\n", command[2], command[1]);
    updateHoleArray(holes, memory);
  }
  else {
    fprintf(output, "The request of %s fail\n", command[1]);
  }
  
}

void allocateFirstFit(process_st* memory, char *command[4], hole_st *holes, FILE *output) {
  long int requested = atoi(command[2]);
  int count;
  int start_index;

  for (int i = 0; i < max;) {
    start_index = i;
    count = 0;

    if (isNullSpace(memory, i)) {
      for (int j = i; j < i + requested; j++) {
        if (isNullSpace(memory, j)) {
          count ++;
        }
      }
      if (count == requested) {  // allocate if true
        for (int k = start_index; k < start_index + requested; k++) {
          strcpy(memory[k].name, command[1]);
          memory[k].start_idx = start_index;
          memory[k].requested = requested;
        }
        i = max;
        fprintf(output, "Allocate %s to %s with First Fit\n", command[2], command[1]);
        updateHoleArray(holes, memory);
      }
      else {
        i = max;
        fprintf(output, "The request of %s fail\n", command[1]);
      }
    }
    i++;
  }
}

void allocateBestFit(process_st* memory, char *command[4], hole_st *holes, FILE *output) {
  long int requested = atoi(command[2]);
  hole_st best_hole;
  for (int i = 0; i < hole_index; i++) {  // first find a hole big enough to fit so can be used as parameter
    if (holes[i].size >= requested) {
      best_hole = holes[i];
      i = hole_index;
    }
  }

  int valid = 0;
  for (int i = 1; i < hole_index; i++) {  // make sure to capture if another hole is more ideal
    if (holes[i].size < best_hole.size && holes[i].size >= requested) {
      best_hole = holes[i];
      valid = 1;
    }
  }

  if (valid || best_hole.size >= requested) {  // allocate if true
    for (int i = best_hole.start_position; i < requested + best_hole.start_position; i++) {
      strcpy(memory[i].name, command[1]);
      memory[i].requested = requested;
      memory[i].start_idx = best_hole.start_position;
    }
    fprintf(output, "Allocate %s to %s with Best Fit\n", command[2], command[1]);
    updateHoleArray(holes, memory);
  }
  else {
    fprintf(output, "The request of %s fail\n", command[1]);
  }
  
}

void compactMemory(process_st *memory, hole_st *holes, FILE *output) {
  process_st processes[max];
  int idx = 0;
  for (int i = 0; i < max;) {
    if (isNullSpace(memory, i)) {
      i++;
    }
    else {
      processes[idx] = memory[i];
      idx++;
      i += memory[i].requested;
    }
  }

  int idx_2 = 0;
  for (int i = 0; i < max; i++) {
    while (idx_2 < idx) {
      for (int j = 0; j < processes[idx_2].requested; j++) {
        memory[i] = processes[idx_2];
        i++;
      }
      idx_2++;
    }
    memory[i] = null_space;
  }
  
  updateHoleArray(holes, memory);
  fprintf(output, "Compact Memory\n");
}

void executeCommand(char *command[4], process_st* memory, hole_st *holes, FILE *output) {
  if (!strcmp(command[0], "X")) {
    fprintf(output, "Exit");
    exit(EXIT_SUCCESS);
  }

  else if (!strcmp(command[0], "STAT")) {
    printMemoryStatus(memory, output);
  }

  else if (!strcmp(command[0], "RQ")) {
    if (!strcmp(command[3], "W")) { allocateWorstFit(memory, command, holes, output); }
    if (!strcmp(command[3], "F")) { allocateFirstFit(memory, command, holes, output); }
    if (!strcmp(command[3], "B")) { allocateBestFit(memory, command, holes, output); }
  }

  else if (!strcmp(command[0], "RL")) {
    releaseMemorySpace(command, memory, holes, output);
  }

  else if (!strcmp(command[0], "C")) {
    compactMemory(memory, holes, output);
  }

  else {
    fprintf(stderr, "Invalid command: '%s'.\n", command[0]);
  }

  updateHoleArray(holes, memory);
}

void readInputFile(FILE *input, process_st *memory, hole_st *holes, FILE *output) {
  char *buffer;
  size_t length = 0;
  char *args[4];
  int index = 0;
  char *slice;
  int true;

  while (getline(&buffer, &length, input) != -1) {
    removeNewLine(buffer);
    true = 1;
    while (true) {
      slice = strtok_r(buffer, " ", &buffer);
      if (slice != NULL) {
        args[index] = slice;
        index++;
      }
      else {
        index = 0;
        true = 0;
        executeCommand(args, memory, holes, output);
      }
    }
  }
}
