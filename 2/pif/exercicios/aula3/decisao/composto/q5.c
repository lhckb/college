#include <stdio.h>

int main()
{
  float salary;

  printf("enter your monthly earning: ");
  scanf("%f", &salary);

  if (salary <= 1000) {
    printf("new salary: %.2f\n", salary * 1.2);
  }
  else if (salary > 1000) {
    printf("new salary: %.2f\n", salary * 1.1);
  }

  return 0;
}