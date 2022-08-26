#include <stdio.h>
#include <math.h>

int main()
{
  int escolha;
  double numero1, numero2;

  printf("1- raiz quadrada de um numero\n");
  printf("2- seno de um numero\n");
  printf("3- produto entre o quadrado de um numero e o cosseno de outro numero\n");
  printf("4- soma entre 2 numeros\n");
  scanf("%i", &escolha);

  switch (escolha) {
    case 1:
      printf("diga um numero: ");
      scanf("%lf", &numero1);
      printf("%.2lf\n", sqrt(numero1));
      break;

    case 2:
      printf("diga um numero: ");
      scanf("%lf", &numero1);
      printf("%.2lf\n", sin(numero1));
      break;
  
    case 3:
      printf("diga dois numeros separados por espaço: ");
      scanf("%lf %lf", &numero1, &numero2);
      printf("%.2lf\n", (pow(numero1, 2) * cos(numero2)));
      break;

    case 4:
      printf("diga dois numeros separados por espaço: ");
      scanf("%lf %lf", &numero1, &numero2);
      printf("%.2lf\n", numero1 + numero2);    
      break;

    default:
      printf("opcao invalida\n");
  }

  return 0;
}