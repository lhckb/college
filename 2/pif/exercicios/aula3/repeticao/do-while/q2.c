#include <stdio.h>

int main()
{
  int num, multiplicado;

  printf("digite um numero pra ver o fatorial dele: ");
  scanf("%i", &num);
  multiplicado = num;

  do {
    multiplicado = multiplicado * --num;

  } while (num > 1);

  printf("o fatorial é %i\n", multiplicado);

  return 0;
}