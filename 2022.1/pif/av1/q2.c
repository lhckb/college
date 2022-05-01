#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 28

int vida1 = 10, vida2 = 10;
int pos1 = 0, pos2 = 0;
char tab[] = {'P', 'B', 'V', 'v', 'B', 'A', 'B', 'L', 'a', 'B', 'V', 'v', 'P', 'A', 'B', 'B', 'V', 'v', 'B', 'a', 'B', 'V', 'v', 'B', 'A', 'V', 'a', 'v', 'P'};
int is_over = 0;
int locked_jog1 = 0, locked_jog2 = 0;

void printBoard()
{
  for (int i = 0; i < SIZE; i++) {
    if (pos1 == i && pos2 == i) {
      printf("3 ");
    }
    else if (pos1 == i) {
      printf("1 ");
    }
    else if (pos2 == i) {
      printf("2 ");
    }
    else {
      printf("%c ", tab[i]);
    }
  }
  printf("\n");
}

int turnPlayer1()
{
  srand(time(NULL));
  int dice1 = 1 + rand()%6;

  printf("rodou %i nos dados\n", dice1);

  pos1 += dice1;
  if (pos1 >= SIZE - 1) {
    is_over = 1;
    printf("jogador 1 venceu com %i de vida!\n", vida1);
  }

  if (tab[pos1] == 'V') {
    vida1 -= 3;
  }
  if (tab[pos1] == 'v') {
    vida1 += 1;
  }
  if (tab[pos1] == 'a') {
    locked_jog1 = 1;
    return 2;
  }
  if (tab[pos1] == 'A') {
    return 3;
  }
  if (tab[pos1] == 'P') {
    pos1 = 0;
  }
}

int turnPlayer2()
{
  srand(time(NULL));
  int dice2 = 1 + rand()%6;

  printf("rodou %i nos dados\n", dice2);

  pos2 += dice2;
  if (pos2 >= SIZE - 1) {
    is_over = 1;
    printf("jogador 2 venceu cm %i de vida!\n", vida2);
  }

  if (tab[pos2] == 'V') {
    vida1 -= 3;
  }
  if (tab[pos2] == 'v') {
    vida1 += 1;
  }
  if (tab[pos2] == 'a') {
    locked_jog2 = 1;
    return 2;
  }
  if (tab[pos2] == 'A') {
    return 3;
  }
  if (tab[pos2] == 'P') {
    pos2 = 0;
  }
}

int defineFirst() 
{
  srand(time(NULL));
  int dice1_1, dice1_2, dice2_1, dice2_2;
  dice1_1 = 1 + rand()%6;
  dice1_2 = 1 + rand()%6;
  dice2_1 = 1 + rand()%6;
  dice2_2 = 1 + rand()%6;

  int jog1_dice = dice1_1 + dice1_2;
  int jog2_dice = dice2_1 + dice2_2;

  if (jog1_dice > jog2_dice) {
    printf("dados do jogador 1 deram %i sobre %i do jogador 2!\n", jog1_dice, jog2_dice);
    return 1;
  }
  else if (jog2_dice > jog1_dice) {
    printf("dados do jogador 2 deram %i sobre %i do jogador 1!\n", jog2_dice, jog1_dice);
    return 2;
  }
  else {
    defineFirst();
  }
}

int main()
{
  printf("-----LEGENDA-----\n");
  printf("1- posição do jogador 1\n2- posição do jogador 2\n3- se os dois estiverem na mesma casa\n\n");
  printf("P- preta\nB- branca\nV- vermelha\nv- verde\na- amarela\nA- azul\n");

  int turn = defineFirst();
  if (turn == 1) {
    printf("jogador 1 inicia!\n");
  }
  else {
    printf("jogador 2 inicia!\n");
  }

  while (is_over == 0) {
    if (locked_jog1 > 0) {
      turn = 2;
      locked_jog1--;
    }
    if (locked_jog2 > 0) {
      turn = 1;
      locked_jog2--;
    }

    if (turn == 1 && locked_jog1 == 0) {
      printf("vez do jogador 1, pressione enter");
      getchar();
      int res = turnPlayer1();
      if (res == 3) {
        turn = 1;
      }
      else {
        turn = 2;
      }
      printBoard();
    }

    printf("\n\n");
    if (is_over) {
      break;
    }

    if (turn == 2 && locked_jog2 == 0) {
      printf("vez do jogador 2, pressione enter");
      getchar();
      int res = turnPlayer2();
      if (res == 3) {
        turn = 2;
      }
      else {
        turn = 1;
      }
      printBoard();
    }

    if (vida1 <= 0) {
      is_over = 1;
      printf("jogador 1 morreu\n");
    }
    else if (vida2 <= 0) {
      is_over = 1;
      printf("jogador 2 morreu\n");
    }
    
    if (vida1 > 10) {
      vida1 = 10;
    }
    if (vida2 > 10) {
      vida2 = 10;
    }

    printf("\nvida jog1: %i\nvida jog2: %i\n\n", vida1, vida2);

  }
}