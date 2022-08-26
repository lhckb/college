#include <stdio.h>

int main()
{
  int mercadorias[100], quantidades[100], escolha, len = 0, codigo, qtd, index;
  float precos[100], preco, total;

  do {
    printf("1- cadastrar mercadoria; 2- consultar mercadoria; 3- valor total em mercadorias; 4- sair\n");
    scanf("%i", &escolha);

    if (escolha == 1) {
      printf("codigo da mercadoria: ");
      scanf("%i", &mercadorias[len]);

      printf("quantidade dessa mercadoria: ");
      scanf("%i", &quantidades[len]);

      printf("preco dessa mercadoria: ");
      scanf("%f", &precos[len]);

      len++;
    }
    else if (escolha == 2) {
      printf("código da mercadoria: ");
      scanf("%i", &codigo);

      for (int i = 0; i < len; i++) {
        if (mercadorias[i] == codigo) {
          index = i;
          break;
        }
      }

      printf("a mercadoria %i tem %i unidades a R$%.2f cada\n", codigo, quantidades[index], precos[index]);

    }
    else if (escolha == 3) {
      total = 0;
      for (int i = 0; i < len; i++) {
        total += quantidades[i] * precos[i];
      }

      printf("o estoque atual tem R$%.2f em mercadorias\n", total);
    }
    else if (escolha == 4) {
      printf("programa encerrado\n");
    }

  } while (escolha != 4);

  return 0;
}