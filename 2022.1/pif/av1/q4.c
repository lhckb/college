#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

char westeros[SIZE][SIZE];
int jon_l = 0, jon_c = 0;
int jon_life = 100, cersei_life = 100, nk_life = 200;
int talked_cersei = 0;

void move_w();
void move_a();
void move_s();
void move_d();

void printWesteros()
{
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c ", westeros[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int cerseiNegotiation()
{
  talked_cersei = 1;

  int attempts = 0;
  int success = 0;
  int negotiation;
  char trash;
  do {
    srand(time(NULL));
    printf("tentar negociação (pressione qualquer tecla): ");
    scanf("%c", &trash);
    negotiation = rand()%101;

    if (negotiation >= 60) {
      success = 1;
      return 1;
    } 
    attempts++;
  } while (attempts < 5 && success == 0);

  printf("negociações falhadas, uma guerra se inicia\n");
  return 0;
}

int attack()
{
  int attack_rate;
  srand(time(NULL));
  attack_rate = rand()%101;

  return attack_rate;
}

int cerseiWar()
{
  int turn = 1;

  do {
    if (turn == 1) {
      printf("vez do jon (pressione qualquer tecla): ");
      getchar();
      int jon = attack();
      if (jon >= 50) {
        cersei_life -= 10;
      }
      turn = 2;
    }
    
    printf("jon: %i\ncersei: %i\n", jon_life, cersei_life);

    if (turn == 2) {
      printf("vez da cersei (pressione qualquer tecla): ");
      getchar();
      int cersei = attack();
      if (cersei >= 50) {
        jon_life -= 10;
      }
      turn = 1;
    }

    printf("jon: %i\ncersei: %i\n", jon_life, cersei_life);
  } while (jon_life > 0 && cersei_life > 0);

  if (jon_life <= 0) {
    printf("voce morreu\n");
    exit(0);
    return 0;
  }
  else {
    printf("a cersei morreu\n");
    return 1;
  }
}

int nightKingWar()
{
  int turn = 1;

  do {
    if (turn == 1) {
      printf("vez do jon (pressione qualquer tecla): ");
      getchar();
      int jon = attack();
      if (jon >= 50) {
        nk_life -= 10;
      }
      turn = 2;
    }

    printf("jon: %i\nrei da noite: %i\n", jon_life, nk_life);

    if (turn == 2) {
      printf("vez do rei da noite (pressione qualquer tecla): ");
      getchar();
      int cersei = attack();
      if (cersei >= 50) {
        jon_life -= 10;
        nk_life += 5;
      }
      turn = 1;
    }

    printf("jon: %i\nrei da noite: %i\n", jon_life, nk_life);
  } while (jon_life > 0 && nk_life > 0);

  if (jon_life <= 0) {
    printf("voce morreu\n");
    exit(0);
    return 0;
  }
  else {
    printf("o rei da noite morreu\n");
    exit(0);
    return 1;
  }
}

void play()
{
  char move;

  do {
    system("clear");
    printf("J- jon\nC- cersei\nN- night king\nE- inimigos\nO- obstaculos\nP- poçoes de vida\n");
    printWesteros();
    printf("jon: %i\ncersei: %i\nrei da noite: %i\n", jon_life, cersei_life, nk_life);
    // printf("movimento: ");
    scanf("%c", &move);
    
    switch (move) {
      case 'w':
        if (westeros[jon_l - 1][jon_c] != 'O' && jon_l > 0) {
          if (westeros[jon_l - 1][jon_c] == 'P') {
            jon_life += 5;
          }
          if (westeros[jon_l - 1][jon_c] == 'E') {
            jon_life--;
          }
          if (westeros[jon_l - 1][jon_c] == 'C') {
            int res = cerseiNegotiation();
            if (res == 1) {
              printf("sucesso!\n");
              jon_life += 100;
            }
            else {
              cerseiWar();
            }
          }
          if (westeros[jon_l - 1][jon_c] == 'N' && talked_cersei == 1) {
            nightKingWar();
          }
          westeros[jon_l][jon_c] = '_';
          jon_l--;
          westeros[jon_l][jon_c] = 'J';
        }
        break;

      case 's':
        if (westeros[jon_l + 1][jon_c] != 'O' && jon_l < 9) {
          if (westeros[jon_l + 1][jon_c] == 'P') {
            jon_life += 5;
          }
          if (westeros[jon_l + 1][jon_c] == 'E') {
            jon_life--;
          }
          if (westeros[jon_l + 1][jon_c] == 'C') {
            int res = cerseiNegotiation();
            if (res == 1) {
              printf("sucesso!\n");
              jon_life += 100;
            }
            else {
              cerseiWar();
            }
          }
          if (westeros[jon_l + 1][jon_c] == 'N' && talked_cersei == 1) {
            nightKingWar();
          }
          westeros[jon_l][jon_c] = '_';
          jon_l++;
          westeros[jon_l][jon_c] = 'J';
        }
        break;

      case 'a':
        if (westeros[jon_l][jon_c - 1] != 'O' && jon_c > 0) {
          if (westeros[jon_l][jon_c - 1] == 'P') {
            jon_life += 5;
          }
          if (westeros[jon_l][jon_c - 1] == 'E') {
            jon_life--;
          }
          if (westeros[jon_l][jon_c - 1] == 'C') {
            int res = cerseiNegotiation();
            if (res == 1) {
              printf("sucesso!\n");
              jon_life += 100;
            }
            else {
              cerseiWar();
            }
          }
          if (westeros[jon_l][jon_c - 1] == 'N' && talked_cersei == 1) {
            nightKingWar();
          }
          westeros[jon_l][jon_c] = '_';
          jon_c--;
          westeros[jon_l][jon_c] = 'J';
        }
        break;

      case 'd':
        if (westeros[jon_l][jon_c + 1] != 'O' && jon_c < 9) {
          if (westeros[jon_l][jon_c + 1] == 'P') {
            jon_life += 5;
          }
          if (westeros[jon_l][jon_c + 1] == 'E') {
            jon_life--;
          }
          if (westeros[jon_l][jon_c + 1] == 'C') {
            int res = cerseiNegotiation();
            if (res == 1) {
              printf("sucesso!\n");
              jon_life += 100;
            }
            else {
              cerseiWar();
            }
          }
          if (westeros[jon_l][jon_c + 1] == 'N' && talked_cersei == 1) {
            nightKingWar();
          }
          westeros[jon_l][jon_c] = '_';
          jon_c++;
          westeros[jon_l][jon_c] = 'J';
        }
        break;
    }

    if (westeros[9][9] = '_') {
      westeros[9][9] = 'N';
    }
    
  } while (jon_life >= 0);
}

void startWesteros()
{
  int rand_l, rand_c;

  westeros[0][0] = 'J';
  westeros[4][4] = 'C';
  westeros[9][9] = 'N';

  // place obstacles
  int qtt_obstacles = 0;
  srand(time(NULL));
  do {
    rand_l = rand()%10;
    rand_c = rand()%10;

    if (westeros[rand_l][rand_c] == '_') {
      westeros[rand_l][rand_c] = 'O';
      qtt_obstacles++;
    }
  } while (qtt_obstacles <= 10);

  // place life potions
  int qtt_potions = 0;
  srand(time(NULL));
  do {
    rand_l = rand()%10;
    rand_c = rand()%10;

    if (westeros[rand_l][rand_c] == '_') {
      westeros[rand_l][rand_c] = 'P';
      qtt_potions++;
    }
  } while (qtt_potions <= 10);

  // place enemies
  int qtt_enemies = 0;
  srand(time(NULL));
  do {
    rand_l = rand()%10;
    rand_c = rand()%10;

    if (westeros[rand_l][rand_c] == '_') {
      westeros[rand_l][rand_c] = 'E';
      qtt_enemies++;
    }
  } while (qtt_enemies <= 20);

  play();
}

int main()
{
  printf("POR FAVOR AGUARDE O JOGO CARREGAR (PODE DEMORAR UM POUCO)\n");

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      westeros[i][j] = '_';
    }
  }

  startWesteros();

  return 0;
}