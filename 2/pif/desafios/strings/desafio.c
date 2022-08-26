#include <stdio.h>
#include <string.h>

int main()
{
  char input[100];
  
  printf("diga uma palavra: ");
  scanf("%s", input);

  int len = strlen(input);

  char palavra[len+1];
  char segredo[len+1];

  for (int i = 0; i < len; i++) {
    palavra[i] = input[i];
  }

  for (int i = 0; i < len-1; i++) {
    segredo[i] = '_';
  }

  char letra;
  int tentativas = len * 3, found, bool = 1;

  while (tentativas >= 0 && bool) {
    getchar();
    printf("%s", segredo);
    printf("\n");
    printf("digite uma letra, voce tem %i tentativas restantes:\n", tentativas);
    scanf("%c", &letra);

    found = 0;

    for (int i = 0; i < len; i++) {
      if (palavra[i] == letra) {
        segredo[i] = letra;
        found = 1;
      }
    }

    if (found != 1) {
      tentativas--;
    }

    if (strcmp(palavra, segredo) == 0) {
      bool = 0;
    }
  }

  if (tentativas <= 0) {
    printf("perdeu\n");
  }
  else {
    printf("ganhou\n");
  }

  return 0;
}