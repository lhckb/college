#include <stdio.h>

int main()
{
  int dinheiro_total = 0, preco, dinheiro_atual, escolha, escolha2;

  do {
    printf("1- atender cliente; 0- fechar caixa\n");
    scanf("%i", &escolha);

    if (escolha == 0) {
      printf("caixa encerrado\n");
    }
    else if (escolha == 1) {
      dinheiro_atual = 0;
      do {
        printf("1- registrar item; 0- encerrar\n");
        scanf("%i", &escolha2);

        if (escolha2 == 0) {
          printf("cliente encerrado\n");
          printf("total: R$%.2f\n", (float)dinheiro_atual);
        }
        else if (escolha2 == 1) {
          printf("digite o preço do item: ");
          scanf("%i", &preco);
          dinheiro_atual += preco;
        }

      } while (escolha2 != 0);

      dinheiro_total += dinheiro_atual;
    }

  } while (escolha != 0);

  printf("o caixa movimentou R$%i hoje\n", dinheiro_total);

  return 0;
}