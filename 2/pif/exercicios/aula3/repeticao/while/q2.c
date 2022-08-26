#include <stdio.h>

int main()
{
  int num, control = 1;

  printf("digite um numero para ver sua tabuada: ");
  scanf("%i", &num);

  while (control <= 10) {
    printf("%i x %i = %i\n", num, control, num * control);
    control++;
  }

  return 0;
}