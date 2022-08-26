#include <stdio.h>

int main()
{
  int num1;

  printf("type in a number: ");
  scanf("%i", &num1);

  if (num1 % 2 == 0) {
    printf("even\n");
  }
  else {
    printf("odd\n");
  }

  return 0;
}