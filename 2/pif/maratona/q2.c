#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loadMatrix(int size, float mat[size][size])
{
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat[i][j] = (float)(rand()%101);
    }
  }
}

void printMatrix(int size, float mat[size][size])
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }
}

float sumElementsInMatrix(int size, float mat[size][size])
{
  float sum = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      sum += mat[i][j];
    }
  }

  return sum;
}

int main()
{
  int input;
  const int size = 10;
  float matrix[size][size];

  do {
    printf("1- carregar matriz\n2- printar matriz\n3- somar elementos da matriz\n5- sair\n\n");
    scanf("%i", &input);
    if (input == 1) {
      loadMatrix(size, matrix);
    }
    else if (input == 2) {
      printMatrix(size, matrix);
    }
    else if (input == 3) {
      float res = sumElementsInMatrix(size, matrix);
      printf("%.2f\n", res);
    }

  } while (input != 5);

  return 0;
}