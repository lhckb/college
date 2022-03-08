#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  srand(time(NULL));

  int a = 1 + rand() % 21;
  int b = 1 + rand() % 21;
  int c = 1 + rand() % 21;

  float res = (-b + sqrt((b*b) + (4 * a * c)) / (2 * a)); 

  printf("%f", res);

  return 0;
}