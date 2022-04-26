#include <stdio.h>

void printBoard(char board[3][3])
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  char board[3][3];
  int count = 1, points = 0, vez = 0, jogada;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '0';
    }
  }

  while (points == 0 && vez < 10) {

    if (vez % 2 == 0) {
      printf("vez do jogador 1\n");
      printf("escolha um lugar no quadro para jogar(1 a 9):\n");
      printBoard(board);
      scanf("%i", &jogada);
      switch (jogada) {
        case 1:
          if (board[0][0] == '0') {
            board[0][0] = 'X';
          }
          break;

        case 2:
          if (board[0][1] == '0') {
            board[0][1] = 'X';
          }
          break;

        case 3:
          if (board[0][2] == '0') {
            board[0][2] = 'X';
          }
          break;

        case 4:
          if (board[1][0] == '0') {
            board[1][0] = 'X';
          }
          break;

        case 5:
          if (board[1][1] == '0') {
            board[1][1] = 'X';
          }
          break;

        case 6:
          if (board[1][2] == '0') {
            board[1][2] = 'X';
          }
          break;

        case 7:
          if (board[2][0] == '0') {
            board[2][0] = 'X';
          }
          break;

        case 8:
          if (board[2][1] == '0') {
            board[2][1] = 'X';
          }
          break;

        case 9:
          if (board[2][2] == '0') {
            board[2][2] = 'X';
          }
          break;
      }
      vez++;
    }
    else {
      printf("vez do jogador 2\n");
      printf("escolha um lugar no quadro para jogar(1 a 9):\n");
      printBoard(board);
      scanf("%i", &jogada);
      switch (jogada) {
        case 1:
          if (board[0][0] == '0') {
            board[0][0] = 'O';
          }
          break;

        case 2:
          if (board[0][1] == '0') {
            board[0][1] = 'O';
          }
          break;

        case 3:
          if (board[0][2] == '0') {
            board[0][2] = 'O';
          }
          break;

        case 4:
          if (board[1][0] == '0') {
            board[1][0] = 'O';
          }
          break;

        case 5:
          if (board[1][1] == '0') {
            board[1][1] = 'O';
          }
          break;

        case 6:
          if (board[1][2] == '0') {
            board[1][2] = 'O';
          }
          break;

        case 7:
          if (board[2][0] == '0') {
            board[2][0] = 'O';
          }
          break;

        case 8:
          if (board[2][1] == '0') {
            board[2][1] = 'O';
          }
          break;

        case 9:
          if (board[2][2] == '0') {
            board[2][2] = 'O';
          }
          break;
      }
      vez++;
    }

    for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
        if (board[i][0] == 'X') {
          printf("jogador 1 vence!\n");
          points = 1;
        }
        else if (board[i][0] == 'O') {
          printf("jogador 2 vence!\n");
          points = 1;
        }
      }
    }

    for (int j = 0; j < 3; j++) {
      if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
        if (board[0][j] == 'X') {
          printf("jogador 1 vence!\n");
          points = 1;
        }
        else if (board[0][j] == 'O') {
          printf("jogador 2 vence!\n");
          points = 1;
        }
      }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
      if (board[1][1] == 'X') {
        printf("jogador 1 vence!\n");
        points = 1;
      }
      else if (board[1][1] == 'O') {
        printf("jogador 2 vence!\n");
        points = 1;
      } 
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
      if (board[1][1] == 'X') {
        printf("jogador 1 vence!\n");
        points = 1;
      }
      else if (board[1][1] == 'O') {
        printf("jogador 2 vence!\n");
        points = 1;
      } 
    }
  }

  printBoard(board);

  return 0;
}
