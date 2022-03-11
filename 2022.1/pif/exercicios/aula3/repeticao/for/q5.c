#include <stdio.h>

int main()
{
  int num;
  int count = 0;

  printf("digite um numero: ");
  scanf("%i", &num);

  for (int i = 1; i < num + 1; i++) {
    if (num % i == 0) {
      count++;
    }
  }

  if (count == 2) {
    printf("é primo\n");
  }
  else {
    printf("não é primo\n");
  }

  return 0;
}