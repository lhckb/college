#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  int board[8][8];
  int torre[2], qtd = 0, bool = 0, hit = 0;

  srand(time(NULL));

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (qtd > 10) {
        board[i][j] = 0;
      }
      else {
        if (rand()%4 == 1) {
          board[i][j] = 1;
          qtd++;
        }
        else {
          board[i][j] = 0;
        }
      }
    }
  }

  while (bool != 1) {
    int i = rand()%8;
    int j = rand()%8;

    if (board[i][j] == 0) {
      board[i][j] == 3;
      torre[0] = i;
      torre[1] = j;
      bool = 1;
    }
  }

  printf("torre está em i=%i j=%i\n", torre[0], torre[1]);

  for (int i = 0; i < 8; i++) {
    if (board[i][torre[1]] == 1) {
      hit = 1;
      printf("elemento está em i=%i j=%i\n", i, torre[1]);
    }
  }

  for (int j = 0; j < 8; j++) {
    if (board[torre[0]][j] == 1) {
      hit = 1;
      printf("elemento está em i=%i j=%i\n", torre[0], j);
    }
  }

  if (hit == 1) {
    printf("jogador 2 derruba alguma pedra\n");
  }
  else {
    printf("jogador 2 não derruba nenhuma pedra\n");
  }

  return 0;
}