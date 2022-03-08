#include <stdio.h>

int main()
{
  char operacao;
  float num1, num2, res;

  printf("escolha a operação (+, -, *, /): ");
  scanf("%c", &operacao);

  printf("diga dois numeros reais separados pro espaço: ");
  scanf("%f %f", &num1, &num2);

  if (operacao == '+') {
    res = num1 + num2;
    printf("%.2f + %.2f = %.2f", num1, num2, res);
  }
  if (operacao == '-') {
    res = num1 - num2;
    printf("%.2f - %.2f = %.2f", num1, num2, res);
  }
  if (operacao == '*') {
    res = num1 * num2;
    printf("%.2f * %.2f = %.2f", num1, num2, res);
  }
  if (operacao == '/') {
    res = num1 / num2;
    printf("%.2f / %.2f = %.2f", num1, num2, res);
  }

  printf("\n");

  return 0;
}