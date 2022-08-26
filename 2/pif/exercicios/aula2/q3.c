#include <stdio.h>

int main()
{
  int installments;
  int installments_paid;
  float total_value;

  printf("total number of installments: ");
  scanf("%i", &installments);

  printf("installments paid so far: ");
  scanf("%i", & installments_paid);

  printf("total value of consortium: ");
  scanf("%f", &total_value);

  float each_installment = total_value / installments;
  float owing_value = total_value - (each_installment * installments_paid);
  int remaining_installments = installments - installments_paid;

  printf("currently owing R$%.2f and you have %i installments left.", owing_value, remaining_installments);
  printf("\n");

  return 0;
}