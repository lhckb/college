#include <stdio.h>

int main()
{
  int senha = 1234, tentativa, tentativas = 3;

  while (tentativas > 0) {
    printf("diga a senha: ");
    scanf("%i", &tentativa);

    if (tentativa == senha) {
      printf("acertou!\n");
      tentativas = 0;
    } 
    else {
      tentativas--;
      printf("errou! voce tem %i tentativas restantes.\n", tentativas);
    }
  }

  return 0;
}