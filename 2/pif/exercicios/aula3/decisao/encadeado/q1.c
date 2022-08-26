#include <stdio.h>

int main()
{
  int dias;
  float total;

  printf("quantos dias voce ficou no hotel? ");
  scanf("%i", &dias);

  if (dias > 15) {
    total = (50 * dias) + (8.5 * dias);
  }
  else if (dias == 15) {
    total = (50 * dias) + (10.0 * dias);
  }
  else {
    total = (50 * dias) + (15.3 * dias);
  }

  printf("o total deu R$%.2f", total);

  return 0;
}