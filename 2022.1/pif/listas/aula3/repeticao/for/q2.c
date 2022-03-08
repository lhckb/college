#include <stdio.h>

int main()
{
  int num, sum = 0;

  scanf("%i", &num);

  for (int i = 0; i < num; i++) {
    if (num % i == 0) {
      sum = sum + i;
    }
  }

  printf("a soma dos divisores de %i é %i\n", num, sum);

  return 0;
}