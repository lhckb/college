#include <stdio.h>

int main()
{
  float salary, installment;

  printf("enter your salary and installment value separated by 1 space: ");
  scanf("%f %f", &salary, &installment);

  if (installment > (0.3 * salary)) {
    printf("loan not authorized\n");
  }
  else {
    printf("loan authorized\n");
  }

  return 0;
}