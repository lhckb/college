#include <stdio.h>

int main()
{
  int i = 0, habs, max, min, consumo, consumo_res = 0, consumo_com = 0, consumo_ind = 0, escolha = 0;

  printf("Numero de habitantes: ");
  scanf("%i", &habs);

  do {
    printf("consumo: ");
    scanf("%i", &consumo);

    if (i == 0) {
      max = consumo;
      min = consumo;
    }
    else {
      if (consumo < min) {
        min = consumo;
      }
      else if (consumo > max) {
        max = consumo;
      }
    }

    printf("1- residencial, 2- comercial, 3- industrial: ");
    scanf("%i", &escolha);

    if (escolha == 1) {
      consumo_res += consumo;
    }
    else if (escolha == 2) {
      consumo_com += consumo;
    }
    else if (escolha == 3) {
      consumo_ind += consumo;
    }

    i++;
  } while (i < habs);

  float media_geral = (consumo_com + consumo_res + consumo_ind) / (float)habs;

  printf("consumo residencial: %i\n", consumo_res);
  printf("consumo comercial: %i\n", consumo_com);
  printf("consumo industrial: %i\n", consumo_ind);
  printf("maior consumo: %i\n", max);
  printf("menor consumo: %i\n", min);
  printf("média do consumo de todos os habitantes: %.3f\n", media_geral);

  return 0;
}