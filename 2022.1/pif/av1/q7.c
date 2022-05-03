#include <stdio.h>

#define SIZE 3

void printIncome(int meias, int inteiras)
{
  printf("o total arrecadado foi: %i\n", meias * 5 + inteiras * 10);
}

void printTickets(int meias, int inteiras)
{
  printf("a quantidade de meias compradas foi de: %i\n", meias);
  printf("a quantidade de inteiras compradas foi de: %i\n", inteiras);
}

void printAvailableSeats(int seats[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%i ", seats[i][j]);
    }
    printf("\n");
  }
}

int selectSeat(int seats[SIZE][SIZE], int l, int c)
{
  if (seats[l][c] == 0) {
    seats[l][c] = 1;
    return 1;
  }
  else {
    return 0;
  }
}

int checkForRoom(int seats[SIZE][SIZE])
{
  int count  = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (seats[i][j] == 0) {
        count++;
      }
    }
  }
  return count;
}

void clearMatrix(int seats[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      seats[i][j] = 0;
    }
  }
}


int main()
{
  int qtt_meias = 0, qtt_inteiras = 0;
  int assentos[SIZE][SIZE];
  
  clearMatrix(assentos);

  int qtt_tickets;
  while (checkForRoom(assentos) > 0) {
    printf("quantos ingressos voce deseja? ");
    scanf("%i", &qtt_tickets);

    if (qtt_tickets > checkForRoom(assentos)) {
      printf("nao ha disponibilidade para essa quantidade\n");
      continue;
    }

    printAvailableSeats(assentos);
    int coord_l, coord_c;
    int m_ou_i;
    for (int i = 0; i < qtt_tickets;) {
      printf("diga as coordenadas do assento que voce quer separadas por 1 espaço: ");
      scanf("%i %i", &coord_l, &coord_c);

      if (selectSeat(assentos, coord_l, coord_c) == 1) {
        printf("1- meia(R$5)\n2- inteira(R$10)\n");
        scanf("%i", &m_ou_i);
        if (m_ou_i == 1) {
          qtt_meias++;
        }
        else if (m_ou_i == 2) {
          qtt_inteiras++;
        }
        i++;
      }
      else {
        printf("assento indisponível, escolha outro\n");
      }
    } 
  }

  printIncome(qtt_meias, qtt_inteiras);
  printTickets(qtt_meias, qtt_inteiras);
  
  return 0;
}