#include <stdio.h>

int main()
{
  float lado1, lado2, lado3;

  printf("digite os 3 lados do triangulo separados por espaço: ");
  scanf("%f %f %f", &lado1, &lado2, &lado3);

  if ((lado1 + lado2) > lado3 && (lado1 + lado3) > lado2 && (lado2 + lado3) > lado1) {
    printf("pode ser triangulo\n");

    if (lado1 == lado2 && lado2 == lado3) {
      printf("triangulo equilatero\n");
    }
    else if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
      printf("triangulo escaleno\n");
    }
    else {
      printf("triangulo isosceles\n");
    }
  }
  else {
    printf("não pode ser triangulo\n");
  }


  return 0;
}