#include <stdio.h>

int main()
{
  int cand1 = 0, cand2 = 0, cand3 = 0, nulos = 0, brancos = 0, total = 0;
  int entrada = 0;

  while (entrada != 6) {
    printf("1- Jair rodrigues; 2- Carlos Luz; 3- Neves Rocha; 4- Nulo; 5- Branco; 6- Parar\n");
    scanf("%i", &entrada);

    switch (entrada) {
      case 1: 
        cand1++;
        total++;
        break;
      
      case 2: 
        cand2++;
        total++;
        break;

      case 3:
        cand3++;
        total++;
        break;

      case 4:
        nulos++;
        total++;
        break;

      case 5:
        brancos++;
        total++;
        break;

      case 6:
        printf("programa encerrado\n");
        break;

      default:
        break;
    }
  }

  printf("candidato 1 recebeu %i votos\n", cand1);
  printf("candidato 2 recebeu %i votos\n", cand2);
  printf("candidato 3 recebeu %i votos\n", cand3);
  printf("nulos correspondem a %.2f%%\n", (float)nulos / total * 100);
  printf("brancos correspondem a %.2f%%\n", (float)brancos / total * 100);
  
  if (cand1 > cand2 && cand1 > cand3) {
    printf("jair rodrigues venceu\n");
  }
  else if (cand2 > cand1 && cand2 > cand3) {
    printf("Carlos Luz venceu\n");
  }
  else if (cand3 > cand1 && cand3 > cand2) {
    printf("Neves Rocha venceu\n");
  }
  else {
    printf("tivemos um empate\n");
  }

  return 0;
}