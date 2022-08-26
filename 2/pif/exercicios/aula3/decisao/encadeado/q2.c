#include <stdio.h>

int main()
{
  int idade;

  printf("qual sua idade? ");
  scanf("%i", &idade);

  if (idade <= 10) {
    printf("pagará R$30\n");
  }
  else if (idade <= 29) {
    printf("pagará R$60\n");
  }
  else if (idade <= 45) {
    printf("pagará R$120\n");
  }
  else if (idade <= 59) {
    printf("pagará R$150\n");
  }
  else if (idade <= 65) {
    printf("pagará R$250\n");
  }
  else {
    printf("pagará R$400\n");
  }

  return 0;
}