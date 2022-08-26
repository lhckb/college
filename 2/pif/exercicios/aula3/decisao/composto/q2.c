#include <stdio.h>

int main()
{
  int num1;

  printf("type in a number: ");
  scanf("%i", &num1);

  if (num1 >= 20 && num1 <= 90) {
    printf("number is between 20 and 90\n");
  }
  else {
    printf("number is out of range\n");
  }

  return 0;
}