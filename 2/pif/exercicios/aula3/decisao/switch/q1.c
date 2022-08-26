#include <stdio.h>

int main()
{
  int dia;

  printf("diga um numero de 1 a 7\n");
  scanf("%i", &dia);

  switch (dia) {
    case 1:
      printf("domingo\n");
      break;

    case 2: 
      printf("segunda feira\n");
      break;

    case 3: 
      printf("terça feira\n");
      break;

    case 4: 
      printf("quarta feira\n");
      break;

    case 5: 
      printf("quinta feira\n");
      break;

    case 6: 
      printf("sexta feira\n");
      break;

    case 7: 
      printf("sábado\n");
      break;

    default:
      printf("numero invalido\n");
  }

  return 0;
}