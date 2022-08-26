#include <stdio.h>

int main()
{
  int x, anterior = 0, atual = 1, count = 2; // considerando o primeiro elemento da sequencia como index 0

  printf("digite um numero: ");
  scanf("%i", &x);

  while (count <= x) {
    int temp = atual;
    atual = anterior + atual;
    anterior = temp;

    count++;
  }

  printf("%i\n", atual);

  return 0;
}