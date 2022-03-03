#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isOdd(int num)
{
  if (num % 2 != 0) {
    return 1;
  }
  return 0;
}


int main()
{ 
  srand(time(NULL));

  int num1 = rand() % 101;
  int num2 = rand() % 101;

  int num3 = 4 + rand() % 5; // random number between 4 and 8

  printf("%i\n", num1);
  printf("%i\n", num2);

  printf("random between 4 and 8: %i\n", num3);

  printf("%i\n", isOdd(1));

  return 0;
}
