#include <stdio.h>

int main()
{
  int tentativas = 15, acertos = 0;
  char car1, car2, car3, chute;

  printf("digite 3 caracteres separados pro espaço: ");
  scanf("%c %c %c", &car1, &car2, &car3);
  getchar();

  do {
    printf("voce tem %i tentativas sobrando\n", tentativas);
    scanf("%c", &chute);
    getchar();

    if (chute == car1) {
      printf("voce acertou o primeiro caracter!\n");
      acertos++;
      void* car1 = NULL;
    }
    else if (chute == car2) {
      printf("voce acertou o segundo caracter!\n");
      acertos++;
      void* car2 = NULL;
    }
    else if (chute == car3) {
      printf("voce acertou o terceiro caracter!\n");
      acertos++;
      void* car3 = NULL;
    }

    tentativas--;

  } while (tentativas > 0 && acertos < 3);

  return 0;
}