#include <stdio.h>
#include <math.h>

int main()
{
  float num1, num2;

  scanf("%f\n%f", &num1, &num2);

  float res1 = sqrt(sin(num1));
  float res2 = pow(num2, cos(num1));

  printf("%f\n%f\n", res1, res2);

  return 0;
}