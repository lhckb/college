#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
  int inscricao;
  float n1, n2, n3, n4;
  float media_final;
  char situacao[13];
} Candidato;

void swap(Candidato arr[], int pos1, int pos2)
{
  Candidato temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

void selectionsort(Candidato arr[])
{
  for (int i = 0; i < 5; i++) {
    int idx_smallest = i;
    for (int j = i; j < 5; j++) {
      if (arr[j].media_final >= arr[idx_smallest].media_final) {
        idx_smallest = j;
      }
    }
    swap(arr, i, idx_smallest);
  }
}

int main()
{
  Candidato candidatos[5];

  for (int i = 0; i < 5; i++) {
    scanf("%i %f %f %f %f", &candidatos[i].inscricao, &candidatos[i].n1, &candidatos[i].n2, &candidatos[i].n3, &candidatos[i].n4);
    float media = (candidatos[i].n1 + candidatos[i].n2 + candidatos[i].n3 + candidatos[i].n4) / 4;
    float media_formatada = floor(media * 100.0f) / 100.0f;
    candidatos[i].media_final = media_formatada;
  }

  selectionsort(candidatos);

  for (int i = 0; i < 5; i++) {
    if (i == 0) {
      strcpy(candidatos[i].situacao, "Classificado");
    }
    else if (candidatos[i].media_final >= 6) {
      strcpy(candidatos[i].situacao, "Aprovado");
    }
    else {
      strcpy(candidatos[i].situacao, "Reprovado");
    }

    printf("%i %.2f %s\n", candidatos[i].inscricao, candidatos[i].media_final, candidatos[i].situacao);
  }

  return 0;
}