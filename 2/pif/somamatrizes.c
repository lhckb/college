#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int tam, int matrix[tam][tam])
{
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n\n\n");
}

void randomlyFillMatrix(int tam, int matrix[tam][tam])
{
  srand(time(NULL));
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      matrix[i][j] = rand()%101;
    }
  }

  printMatrix(tam, matrix);
}

void sumTwoMatrixes(int tam, int matrix1[tam][tam], int matrix2[tam][tam])
{
  int res_matrix[tam][tam];

  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      res_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  printMatrix(tam, res_matrix);
}

int main()
{
  const int tam = 10;
  int mat1[tam][tam], mat2[tam][tam];

  randomlyFillMatrix(tam, mat1);
  randomlyFillMatrix(tam, mat2);

  sumTwoMatrixes(tam, mat1, mat2);

  return 0;
}