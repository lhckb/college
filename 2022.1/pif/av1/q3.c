#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int eleven_l, eleven_c, taxa_raiva = 0, vida = 100;
char classroom[3][3];
char upsidedown[10][10];
int portal_l, portal_c;
int *will_l, *will_c;
int demodog_coords[4][2];

void clearBoard(int size, char board[size][size])
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = '_';
    }
  }
}

void printBoard(int size, char board[size][size])
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int placeElement(int l, int c, int size, char board[size][size], char el)
{
  if (board[l][c] == '_') {
    board[l][c] = el;
    return 1;
  }
  return 0;
}

void moveWill(int *will_l, int *will_c)
{
  srand(time(NULL));
  int possible1 = rand()%2;
  int possible2;
  if (possible1 == 0) {
    possible2 = rand()%2;
    if (possible2 == 0) {
      *will_l++;
    }
    else {
      *will_l--;
    }
  }
  else {
    possible2 = rand()%2;
    if (possible2 == 0) {
      *will_c++;
    }
    else {
      *will_c--;
    }
  }
}

int demodogEncounter(int el_l, int el_c)
{
  for (int i = 0; i < 4; i++) {
    if (demodog_coords[i][0] == el_l && demodog_coords[i][1] == el_c) {
      demodog_coords[i][0] = -1;
      demodog_coords[i][1] = -1;
      return 1;
    }
  }
  return 0;
}

void startUpsideDown()
{
  printf("AGUARDE ENQUANTO O JOGO CARREGA (é sério)\n");
  int rand_l, rand_c;
  for (int i = 0; i < 20; i++) {
  int count = 0;
    do {
      srand(time(NULL));
      rand_l = rand()%10;
      rand_c = rand()%10;
      if (upsidedown[rand_l][rand_c] == '_') {
        upsidedown[rand_l][rand_c] = 'O';
        count++;
      }
    } while (count < 1);
  }

  int is_eleven_placed = 0;
  do {
    srand(time(NULL));
    rand_l = rand()%10;
    rand_c = rand()%10;
    if (upsidedown[rand_l][rand_c] == '_') {
      upsidedown[rand_l][rand_c] = 'E';
      eleven_l = rand_l;
      eleven_c = rand_c;
      is_eleven_placed = 1;
    }
  } while (is_eleven_placed != 1);

  for (int i = 0; i < 4; i++) {
    int cond = 1;
    do {
      srand(time(NULL));
      demodog_coords[i][0] = rand()%10;
      demodog_coords[i][1] = rand()%10;
      if (upsidedown[demodog_coords[i][0]][demodog_coords[i][1]] == '_') {
        cond = 0;
      }
    } while (cond); 
  }

  int rand_pancake_l, rand_pancake_c;
  for (int i = 0; i < 10; i++) {
    int cond = 1;
    do {
      srand(time(NULL));
      rand_pancake_l = rand()%10;
      rand_pancake_c = rand()%10;
      if (upsidedown[rand_pancake_l][rand_pancake_c] == '_') {
        upsidedown[rand_pancake_l][rand_pancake_c] = 'P';
        cond = 0;
      }
    } while (cond); 
  }

  int is_will_ok = 0, is_over = 0;
  do {
    char move;
    printBoard(10, upsidedown);
    printf("vida: %i\n", vida);
    printf("movimento: \n");
    scanf("%c", &move);

    switch (move) {
      case 'w':
        if ((upsidedown[eleven_l - 1][eleven_c] == '_' || upsidedown[eleven_l - 1][eleven_c] == 'P' || upsidedown[eleven_l - 1][eleven_c] == 'W') && eleven_l - 1 >= 0) {
          if (demodogEncounter(eleven_l, eleven_c) == 1) {
            printf("encontrou um demodog\n");
            vida -= 10;
          }
          if (upsidedown[eleven_l - 1][eleven_c] == 'P') {
            vida += 5;
          }
          upsidedown[eleven_l][eleven_c] = '_';
          eleven_l--;
          upsidedown[eleven_l][eleven_c] = 'E';
        }
        break;

      case 's':
        if ((upsidedown[eleven_l + 1][eleven_c] == '_' || upsidedown[eleven_l + 1][eleven_c] == 'P' || upsidedown[eleven_l + 1][eleven_c] == 'W') && eleven_l + 1 < 10) {
          if (demodogEncounter(eleven_l, eleven_c) == 1) {
            printf("encontrou um demodog\n");
            vida -= 10;
          }
          if (upsidedown[eleven_l + 1][eleven_c] == 'P') {
            vida += 5;
          }
          upsidedown[eleven_l][eleven_c] = '_';
          eleven_l++;
          upsidedown[eleven_l][eleven_c] = 'E';
        }
        break;

      case 'a':
        if ((upsidedown[eleven_l][eleven_c - 1] == '_' || upsidedown[eleven_l][eleven_c - 1] == 'P' || upsidedown[eleven_l][eleven_c - 1] == 'W') && eleven_c - 1 >= 0) {
          if (demodogEncounter(eleven_l, eleven_c) == 1) {
            printf("encontrou um demodog\n");
            vida -= 10;
          }
          if (upsidedown[eleven_l][eleven_c - 1] == 'P') {
            vida += 5;
          }
          upsidedown[eleven_l][eleven_c] = '_';
          eleven_c--;
          upsidedown[eleven_l][eleven_c] = 'E';
        }
        break;          

      case 'd':
        if ((upsidedown[eleven_l][eleven_c + 1] == '_' || upsidedown[eleven_l][eleven_c + 1] == 'P' || upsidedown[eleven_l][eleven_c + 1] == 'W') && eleven_c + 1 < 10) {
          if (demodogEncounter(eleven_l, eleven_c) == 1) {
            printf("encontrou um demodog\n");
            vida -= 10;
          }
          if (upsidedown[eleven_l][eleven_c + 1] == 'P') {
            vida += 5;
          }
          upsidedown[eleven_l][eleven_c] = '_';
          eleven_c++;
          upsidedown[eleven_l][eleven_c] = 'E';
        }
        break;
    }

    if (vida > 100) {
      vida = 100;
    }

    system("clear");
  } while(is_over != 1);
}

void startClassroom()
{
  srand(time(NULL));
  eleven_c = 1;
  eleven_l = 1;
  classroom[1][1] = 'E';

  int cond = 1;
  do {
    taxa_raiva = rand()%101;
    printf("taxa raiva: %i\n", taxa_raiva);

    if (taxa_raiva >= 60) {
      cond = 0;
    }
    else {
      vida -= 20;
      if (vida <= 0) {
        printf("voce morreu.\n");
        exit(1);
      }
      printf("sua vida está em %i, pressione qualquer tecla para continuar.\n", vida);
      printBoard(3, classroom);
      getchar();
    }

  } while (vida > 0 && cond == 1);

  int res;
  do {
    portal_c = rand()%3;
    portal_l = rand()%3;
    res = placeElement(portal_l, portal_c, 3, classroom, 'P');
  } while (res == 0);

  char move;
  do {
    printBoard(3, classroom);
    printf("vida: %i\n", vida);
    printf("movimento: \n");
    scanf("%c", &move);

    switch (move) {
      case 'w':
        if (classroom[eleven_l - 1][eleven_c] == '_'||'P' && eleven_l - 1 >= 0) {
          classroom[eleven_l][eleven_c] = '_';
          eleven_l--;
          classroom[eleven_l][eleven_c] = 'E';
        }
        break;

      case 's':
        if (classroom[eleven_l + 1][eleven_c] == '_'||'P' && eleven_l + 1 <= 2) {
          classroom[eleven_l][eleven_c] = '_';
          eleven_l++;
          classroom[eleven_l][eleven_c] = 'E';
        }
        break;

      case 'a':
        if (classroom[eleven_l][eleven_c - 1] == '_'||'P' && eleven_c - 1 >= 0) {
          classroom[eleven_l][eleven_c] = '_';
          eleven_c--;
          classroom[eleven_l][eleven_c] = 'E';
        }
        break;          

      case 'd':
        if (classroom[eleven_l][eleven_c + 1] == '_'||'P' && eleven_c + 1 <= 2) {
          classroom[eleven_l][eleven_c] = '_';
          eleven_c++;
          classroom[eleven_l][eleven_c] = 'E';
        }
        break;
    }
    
    system("clear");
  } while (eleven_c != portal_c || eleven_l != portal_l);

  startUpsideDown();
}


int main()
{
  clearBoard(3, classroom);
  clearBoard(10, upsidedown);

  startClassroom();

  return 0;
}
