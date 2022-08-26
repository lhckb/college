#include <stdio.h>

int main()
{
  int num1, num2;

  printf("type in 2 numbers: ");
  scanf("%i %i", &num1, &num2);

  int res = num1 + num2;

  if (res > 10) {
    printf("%i", res);
  }

  printf("\n");

  return 0;
}