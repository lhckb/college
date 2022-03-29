#include <stdio.h>

void printMatrix(int tam, int matrix[tam][tam])
{
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  const int tam = 5;
  int sala[5][5];
  int jogo_ok = 1;
  int qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0;

  // zerar a matriz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      sala[i][j] = 0;
    }
  }

  // inicializar os itens
  sala[0][3] = 1;
  sala[0][4] = 1;
  sala[1][3] = 2;
  sala[1][4] = 1;
  sala[2][3] = 2;
  sala[2][4] = 2;
  sala[3][3] = 3;
  sala[3][4] = 4;
  sala[4][3] = 3;
  sala[4][4] = 4;

  // inicializar player
  int jog_l = 0;
  int jog_c = 0;
  sala[0][0] = 9;

  printf("voce será representado pelo numero 9!\n");
  printf("use 'wasd'\n\n");

  do {
    printMatrix(tam, sala);

    char move;

    printf(">>> ");
    scanf("%c", &move);
    getchar();

    switch (move) {
      case 'w':
        if (jog_l > 0) {
          if (sala[jog_l-1][jog_c] == 1) {
            qtd1++;
          }
          if (sala[jog_l-1][jog_c] == 2) {
            qtd2++;
          }
          if (sala[jog_l-1][jog_c] == 3) {
            qtd3++;
          }
          if (sala[jog_l-1][jog_c] == 4) {
            qtd4++;
          }
          sala[jog_l][jog_c] = 0;
          jog_l--;
          sala[jog_l][jog_c] = 9;
        }
        break;
      
      case 's':
        if (jog_l < 4) {
          if (sala[jog_l+1][jog_c] == 1) {
            qtd1++;
          }
          if (sala[jog_l+1][jog_c] == 2) {
            qtd2++;
          }
          if (sala[jog_l+1][jog_c] == 3) {
            qtd3++;
          }
          if (sala[jog_l+1][jog_c] == 4) {
            qtd4++;
          }
          sala[jog_l][jog_c] = 0;
          jog_l++;
          sala[jog_l][jog_c] = 9;
        }
        break;

      case 'a':
        if (jog_c > 0) {
          if (sala[jog_l][jog_c-1] == 1) {
            qtd1++;
          }
          if (sala[jog_l][jog_c-1] == 2) {
            qtd2++;
          }
          if (sala[jog_l][jog_c-1] == 3) {
            qtd3++;
          }
          if (sala[jog_l][jog_c-1] == 4) {
            qtd4++;
          }
          sala[jog_l][jog_c] = 0;
          jog_c--;
          sala[jog_l][jog_c] = 9;
        }
        break;
      
      case 'd':
        if (jog_c < 4) {
          if (sala[jog_l][jog_c+1] == 1) {
            qtd1++;
          }
          if (sala[jog_l][jog_c+1] == 2) {
            qtd2++;
          }
          if (sala[jog_l][jog_c+1] == 3) {
            qtd3++;
          }
          if (sala[jog_l][jog_c+1] == 4) {
            qtd4++;
          }
          sala[jog_l][jog_c] = 0;
          jog_c++;
          sala[jog_l][jog_c] = 9;
        }
        break;

      default:
        printf("comando invalido\n");
        break;
    }

    if (qtd1 > 1 || qtd2 > 1 || qtd3 > 1 || qtd4 > 1) {
      printf("você foi preso\n");
      jogo_ok = 0;
    }
    else if ((jog_l == 0 && jog_c == 0) && (qtd1 == 1 && qtd2 == 1 && qtd3 == 1 && qtd4 == 1)) {
      printf("voce escapou! \n");
      jogo_ok = 0;
    }

  } while (jogo_ok);

  return 0;
}