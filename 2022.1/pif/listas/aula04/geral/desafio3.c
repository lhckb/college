#include <stdio.h>

int main()
{
  int chute, vez = 0, flipped = 0, try = 1, pontos_j1 = 0, pontos_j2 = 0;
  char board[2][2] = {{'a', 'b'}, {'b', 'a'}};
  char atual;

  while (flipped < 2) {
    if (vez % 2 == 0) {
      printf("vez do  jogador 1\n");
      printf("diga uma posicao no quadro (1 a 4): ");
      scanf("%i", &chute);

      switch (chute) {
        case 1:
          if (try == 1) {
            atual = board[0][0];
            printf("seu chute é %c\n", board[0][0]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[0][0]);
            if (board[0][0] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j1++;
            }
          try = 1;
          vez++;
          }
          break;

        case 2:
          if (try == 1) {
            atual = board[0][1];
            printf("seu chute é %c\n", board[0][1]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[0][1]);
            if (board[0][1] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j1++;
            }
          try = 1;
          vez++;
          }
          break;

        case 3:
          if (try == 1) {
            atual = board[1][0];
            printf("seu chute é %c\n", board[1][0]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[1][0]);
            if (board[1][0] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j1++;
            }
          try = 1;
          vez++;
          }
          break;

        case 4:
          if (try == 1) {
            atual = board[1][1];
            printf("seu chute é %c\n", board[1][1]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[1][1]);
            if (board[1][1] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j1++;
            }
          try = 1;
          vez++;
          }
          break;
      }
    }


    if (vez % 2 != 0) {
      printf("vez do  jogador 2\n");
      printf("diga uma posicao no quadro (1 a 4): ");
      scanf("%i", &chute);

      switch (chute) {
        case 1:
          if (try == 1) {
            atual = board[0][0];
            printf("seu chute é %c\n", board[0][0]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[0][0]);
            if (board[0][0] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j2++;
            }
          try = 1;
          vez++;
          }
          break;

        case 2:
          if (try == 1) {
            atual = board[0][1];
            printf("seu chute é %c\n", board[0][1]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[0][1]);
            if (board[0][1] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j2++;
            }
          try = 1;
          vez++;
          }
          break;

        case 3:
          if (try == 1) {
            atual = board[1][0];
            printf("seu chute é %c\n", board[1][0]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[1][0]);
            if (board[1][0] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j2++;
            }
          try = 1;
          vez++;
          }
          break;

        case 4:
          if (try == 1) {
            atual = board[1][1];
            printf("seu chute é %c\n", board[1][1]);
            try++;
          }
          else if (try == 2) {
            printf("seu chute é %c\n", board[1][1]);
            if (board[1][1] == atual) {
              flipped++;
              for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                  if (board[i][j] == atual) {
                    board[i][j] = 'z';
                  }
                }
              }
              atual = 'c';
              pontos_j2++;
            }
          try = 1;
          vez++;
          }
          break;
      }
    }
  } 

  if (pontos_j1 > pontos_j2) {
    printf("vitória do jogador 1\n");
  }
  else if (pontos_j1 < pontos_j2) {
    printf("vitória do jogador 2\n");
  }
  else {
    printf("empate\n");
  }

  return 0;
}