#include <stdio.h>

typedef struct {
  char nome[30];
  char cpf[11];
  int salario;
} Funcionario;

int somaSalariosRecursivo(Funcionario array[], int size)
{
  if (size == 0) {
    return array[0].salario;
  }
  else {
    return array[size].salario + somaSalariosRecursivo(array, size - 1);
  }
}

int main()
{
  int qtd;
  printf("diga quantos funcionários deseja cadastrar: ");
  scanf("%i", &qtd);

  Funcionario funcionarios[qtd];

  for (int i = 0; i < qtd; i++) {
    printf("digite o nome: ");
    scanf(" %[^\n]", funcionarios[i].nome);

    printf("digite o cpf: ");
    scanf(" %[^\n]", funcionarios[i].cpf);

    printf("digite o salario: ");
    scanf("%i", &funcionarios[i].salario);
  }

  if (qtd > 0) {
    int res = somaSalariosRecursivo(funcionarios, qtd-1);
    printf("a soma dos salários é: %i\n", res);
  }

  return 0;
}