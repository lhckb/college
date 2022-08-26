#include <stdio.h>


int main()
{
  int linhas, colunas;

  do {
    printf("digite a quantidade de linhas na matriz: ");
    scanf("%i", &linhas);

    printf("digite a quantidade de colunas na matriz: ");
    scanf("%i", &colunas);
  } while ((linhas > 10 || linhas < 0) && (colunas > 10 || colunas < 0));

  int matrix[linhas][colunas];

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      int input;
      do {
        printf("digite o numero a ocupar a posição [%i][%i]: ", i, j);
        scanf("%i", &input);

        matrix[i][j] = input;

      } while (input < 0 || input > 20);
    }
  }

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      int curr = matrix[i][j];
      int curr_count = 0;

      if (curr != -1) {
        for (int x = 0; x < linhas; x++) {
          for (int y = 0; y < colunas; y++) {
            if (matrix[x][y] == curr) {
              curr_count++;
              matrix[x][y] = -1;
            }
          }
        }
        printf("%i = %i\n", curr, curr_count);
      }
    }
  }

  return 0;
}