#include <stdio.h>

int main()
{
  int escolha, idade;

  printf("diga sua idade: ");
  scanf("%i", &idade);

  printf("escolha o filme:\n");
  printf("1- Titanic\n");
  printf("2- Pica Pau\n");
  printf("3- A volta de Jason\n");
  printf("4- Desistir\n");
  scanf("%i", &escolha);

  if (escolha == 1) {
    if (idade >= 16) {
      printf("Voce comprou ingresso para Titanic. Bom filme!\n");
    }
    else {
      printf("voce nao tem idade para ver esse filme\n");
    }
  }

  if (escolha == 2) {
    printf("Voce comprou ingresso para Pica Pau. Bom filme!\n");
  }

  if (escolha == 3) {
    if (idade >= 18) {
      printf("Voce comprou ingresso para A volta de Jason. Bom filme!\n");
    }
    else {
      printf("voce nao tem idade para ver esse filme\n");
    }
  }

  if (escolha == 4) {
    printf("programa encerrado.\n");
  }

  return 0;
}