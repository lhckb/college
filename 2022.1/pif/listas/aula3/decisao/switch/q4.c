#include <stdio.h>

int main()
{
  int codigo, quantidade;

  printf("digite o codigo do item:\n");
  printf("100- cachorro quente\n");
  printf("101- bauru simples\n");
  printf("102- bauru com ovo\n");
  printf("103- hamburger\n");
  printf("104- cheeseburger\n");
  printf("105- refrigerante\n");
  scanf("%i", &codigo);

  printf("diga a quantidade do item: ");
  scanf("%i", &quantidade);

  switch (codigo) {
    case 100:
      printf("total: R$%.2f\n", quantidade * 1.2);
      break;

    case 101:
      printf("total: R$%.2f\n", quantidade * 1.3);
      break;

    case 102:
      printf("total: R$%.2f\n", quantidade * 1.5);
      break;

    case 103:
      printf("total: R$%.2f\n", quantidade * 1.2);
      break;

    case 104:
      printf("total: R$%.2f\n", quantidade * 1.3);
      break;

    case 105:
      printf("total: R$%.2f\n", quantidade * 1.0);
      break;
  }
  
  return 0;
}