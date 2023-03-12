#ifndef UTILS_H
#define UTILS_H

#define BIG_NUM 100

#include <stdio.h>

typedef struct process_st {
  char name[BIG_NUM];
  int requested;
  int start_idx;
} process_st;

typedef struct hole_st {
  int start_position;
  int size;
} hole_st;

int isNullSpace(process_st *memory, int index);

void removeNewLine(char *line);

void printHoleArray(hole_st *holes);

void updateHoleArray(hole_st *holes, process_st* memory);

void initMemory(process_st *memory);

void printMemoryStatus(process_st *memory, FILE *output); 

void releaseMemorySpace(char *command[4], process_st *memory, hole_st *holes, FILE *output);

void allocateWorstFit(process_st* memory, char *command[4], hole_st *holes, FILE *output);

void allocateFirstFit(process_st* memory, char *command[4], hole_st *holes, FILE *output);

void allocateBestFit(process_st* memory, char *command[4], hole_st *holes, FILE *output);

void compactMemory(process_st *memory, hole_st *holes, FILE *output);

void executeCommand(char *command[4], process_st* memory, hole_st *holes, FILE *output);

void readInputFile(FILE* input, process_st* memory, hole_st* holes, FILE *output);

#endif