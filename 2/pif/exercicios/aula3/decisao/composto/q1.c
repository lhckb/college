#include <stdio.h>

int main()
{
  int a, b;

  printf("type in two numbers: ");
  scanf("%i %i", &a, &b);

  if (a % b == 0) {
    printf("divisible\n");
  }
  else {
    printf("not divisible\n");
  }

  return 0;
}