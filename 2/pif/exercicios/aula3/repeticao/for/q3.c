#include <stdio.h>

int main()
{
  int num_habs, filhos = 0, mais2kids = 0, tempfilhos;
  float salarios = 0, max_sal = 0, min_sal = 0, tempsal;

  printf("quantos habitantes cadastrar? ");
  scanf("%i", &num_habs);

  for (int i = 0; i < num_habs; i++) {
    printf("quantos filhos? ");
    scanf("%i", &tempfilhos);

    filhos += tempfilhos;
    if (tempfilhos > 2) {
      mais2kids++;
    }

    printf("salário: ");
    scanf("%f", &tempsal);

    salarios += tempsal;

    if (i == 0) {
      max_sal = tempsal;
      min_sal = tempsal;
    }
    else if (tempsal > max_sal) {
      max_sal = tempsal;
    }
    else if (tempsal < min_sal) {
      min_sal = tempsal;
    }
  }

  printf("media dos salarios: %.2f\n", salarios / num_habs);
  printf("maior salario: %.2f e menor salario: %.2f\n", max_sal, min_sal);
  printf("média num de filhos: %.2f\n", (float)filhos / num_habs);
  printf("percentual que tem mais de 2 filhos: %.2f\n", ((float)mais2kids / num_habs)*100);

  return 0;
}