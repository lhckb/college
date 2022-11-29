#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"

int max;
process_st null_space;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Wrong number of arguments to './memory [MAX] [filename]' expected 2, received %d\n", argc - 1);
  }

  strcpy(null_space.name, "NULL");

  max = atoi(argv[1]);

  hole_st holes[max / 2 + 1];
  process_st memory[max];
  initMemory(memory);
  updateHoleArray(holes, memory);

  FILE* input = fopen(argv[2], "r");
  if (input == NULL) {
    fprintf(stderr, "File '%s' not found.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  FILE *output = fopen("memory_lhcc.out", "w");
  if (output == NULL) {
    fprintf(stderr, "Could not create output file.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(output, "Total Memory %d\n", max);
  readInputFile(input, memory, holes, output);

  fclose(output);
  fclose(input);

  exit(EXIT_SUCCESS);
}