#include <stdio.h>

int main()
{
  float lab, semestre, final, media, rec, media_final;

  printf("digite as 3 notas separadas por espaço: ");
  scanf("%f %f %f", &lab, &semestre, &final);

  media = ((lab * 2) + (semestre * 3) + (final * 5)) / 10;

  if (media < 3) {
    printf("REPROVADO\n");
  }
  else if (media < 5) {
    printf("RECUPERAÇÃO! digite a nota da recuperação: ");
    scanf("%f", &rec);
    media_final = (rec + final) / 2;

    if (media_final >= 5) {
      printf("APROVADO\n");
    }
    else {
      printf("REPROVADO\n");
    }
  }
  else {
    printf("APROVADO\n");
  }

  return 0;
}