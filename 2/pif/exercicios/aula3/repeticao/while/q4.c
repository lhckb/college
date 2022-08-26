#include <stdio.h>

int main()
{
  int escolha = 0;

  while (escolha != 3) {
    printf("1- olá; 2- bem vindo; 3- sair:\n");
    scanf("%i", &escolha);

    if (escolha == 1) {
      printf("olá\n");
    }
    else if (escolha == 2) {
      printf("bem vindo\n");
    }
    else if (escolha == 3) {
      printf("programa encerrado\n");
    }
  }

  return 0;
}