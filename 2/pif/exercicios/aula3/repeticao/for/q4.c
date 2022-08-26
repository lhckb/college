#include <stdio.h>

int main()
{
  int idade, qnt_bom = 0, qnt_rglr = 0, opiniao, idades_exc = 0, qnt_exc = 0;

  for (int i = 0; i < 10; i++) {
    printf("1- regular; 2- bom; 3- excelente\n");
    scanf("%i", &opiniao);

    printf("idade: ");
    scanf("%i", &idade);

    if (opiniao == 3) {
      idades_exc += idade;
      qnt_exc++;
    }
    else if (opiniao == 2) {
      qnt_bom++;
    }
    else if (opiniao == 1) {
      qnt_rglr++;
    }
  }

  printf("média das idades dos que responderam excelente: %.2f\n", (float)idades_exc / qnt_exc);
  printf("quantidade que responderam regular: %i\n", qnt_rglr);
  printf("percentagem que respondeu bom entre todos: %.2f\n", ((float)qnt_bom / 10) * 100);

  return 0;
}