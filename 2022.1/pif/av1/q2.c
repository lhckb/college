#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void tabuleiro(J1, J2) {
  int x, y, c;
  char cor;
  for (x = 0; x < 10; x++)
    printf("+--------");

  printf("+\n");
  for (x = 0; x < 7; x++) {
    for (y = 0; y < 10; y++) {

      if (x == 0 || ((x != 1 || x != 2) && y > 8) || x == 6)
        printf("|");

      else
        printf(" ");

      if ((J1 < 9) && (x == 0 && y == J1))
        printf("J1");

      else if ((J1 < 16) && (x == (J1 - 9) && y == 9))
        printf("J1");

      else if ((J1 > 15) && (x == 6 && y == (25 - J1)))
        printf("J1");

      else if ((J1 > 25) && (x == (31 - J1) && y == 0))
        printf("J1");

      else
        printf("  ");

      if (((x == 0 || x == 3) && y == 0) || (x == 2 && y == 9)) // PRETO
        printf(" Pr ");

      else if ((x == 0 && (y == 1 || y == 4 || y == 6 || y == 8)) ||
               (x == 4 && y == 9) || (x == 5 && (y == 0 || y == 9)) ||
               (x == 6 && (y == 5 || y == 6))) // BRANCO
        printf(" Br ");

      else if ((x == 0 && (y == 2 || y == 9)) ||
               (x == 6 && (y == 0 || y == 4 || y == 9))) // VERMELHO
        printf(" Vr ");

      else if ((x == 0 && y == 3) || (x == 1 && y == 9) || (x == 4 && y == 0) ||
               (x == 6 && (y == 3 || y == 8))) // VERDE
        printf(" Vd ");

      else if ((x == 0 && y == 5) || (x == 3 && y == 9) ||
               (x == 6 && y == 1)) // AZUL
        printf(" Az ");

      else if (x == 0 || x == 6) // AMARELO
        printf(" Am ");

      else
        printf("    ");

      if ((J2 < 9) && (x == 0 && y == J2))
        printf("J2");

      else if ((J2 < 16) && (x == (J2 - 9) && y == 9))
        printf("J2");

      else if ((J2 > 15) && (x == 6 && y == (25 - J2)))
        printf("J2");

      else if ((J2 > 25) && (x == (31 - J2) && y == 0))
        printf("J2");

      else
        printf("  ");

      // if(x>2 && y<1)
      //  printf("|");

      // else
      //  printf("        ");
    }
    printf("|\n");

    if (x == 0 || x > 4)
      printf("+--------+--------+--------+--------+--------+--------+--------+-"
             "-------+--------+--------+");
    else if (x != 1)
      printf("+--------+                                                       "
             "                +--------+");
    else
      printf("                                                                 "
             "                +--------+");

    printf("\n");
  }
}
// struct de vida e posição do jogador
typedef struct Jogador {
  int vida;
  int position;
  bool your_turn;

} p1, p2;

// gerar numeros aleatorios p o dado
int rolar_dado() {
  int saida;
  saida = (rand() % 6) + 1;
  return saida;
}


int main() {
  srand(time(NULL));
  int r = 0, a, b, i, j, soma1, soma2;

  int p1_vida = 10;
  int p1_position = 0;
  int p2_vida = 10;
  int p2_position = 0;
  int dado;
  bool p1_your_turn = 0, p2_your_turn = 0, p1_am = 0, p2_am = 0;

  
  printf("INICIO DO JOGO: \n");
  printf("pressione enter para começar: \n");
  getc(stdin);

  while (r == 0) {
    printf("quem obter a maior soma dos dados começa o jogo!\n ");

    printf("jogando os dados do jogador 1: \n\n");
    a = rolar_dado();
    b = rolar_dado();
    soma1 = a + b;
    printf("%d %d\nsoma = %d\n", a, b, soma1);

    printf("jogando os dados do jogador 2: \n\n");
    a = rolar_dado();
    b = rolar_dado();
    soma2 = a + b;
    printf("%d %d\nsoma = %d\n", a, b, soma2);

    if (soma1 == soma2) {
      printf("Empate! Rolem novamente.\n\n");
      r = 0;
    } else if (soma1 > soma2) {
      printf("O jogador 1 ira começar!\n\n");
      p1_your_turn = 1;
      p2_your_turn = 0;
      r = 1;
    } else if (soma2 > soma1) {
      printf("O jogador 2 ira começar!\n\n");
      p1_your_turn = 0;
      p2_your_turn = 1;
      r = 1;
    }
    printf("celula branca: espaço neutro\n");
    printf("celula vermelha: -3 vidas\n");
    printf("celula verde: +1 vida\n");
    printf("celula amarela: 1 turno sem jogar\n");
    printf("celula azul: jogador joga novamente\n");
    printf("celula preta: jogador volta ao inicio\n\n");
  }


  // posicao = dado;
  // if(p1_your_turn){
  // tab2[p1_position][0] = 0;
  // verificar posicao no array
  // zerar posicao no array
  // andar jogador 1

  tabuleiro(p1_position, p2_position);

  while ((p1_position < 28) && (p2_position < 28) && (p1_vida > 0) && (p2_vida > 0)) {
    if (p1_your_turn == 1) {
      if (p1_am == 1) {
        printf("Jogador 1 nao ira jogar\n");

        p1_your_turn = 0;
        p2_your_turn = 1;
        p1_am = 0;
        printf("vidas do jogador 1: %d\n", p1_vida);
      } 
      else {
        printf("Vez do jogador 1, role!\n");
        
        getc(stdin);
        printf("Dado: %d\n", dado = rolar_dado());
        p1_position = p1_position + dado;
        

        
        // JOGADOR 1

        if (p1_position == 0 || p1_position == 12) {
          p1_position = 0;
          p1_your_turn = 0;
          p2_your_turn = 1;
          printf("vidas do jogador 1: %d\n", p1_vida);
        }

        else if (p1_position == 2 || p1_position == 9 || p1_position == 15 || p1_position == 24) {
          p1_vida = p1_vida - 3;
          p1_your_turn = 0;
          p2_your_turn = 1;
          printf("vidas do jogador 1: %d\n", p1_vida);
        }

        else if (p1_position == 7 || p1_position == 18 || p1_position == 26) {
          p1_am = 0;
          p1_your_turn = 0;
          p2_your_turn = 1;
          printf("vidas do jogador 1: %d\n", p1_vida);

        }

        else if (p1_position == 3 || p1_position == 10 || p1_position == 17 || p1_position == 22 || p1_position == 27) {
          if (p1_vida < 10) {
            p1_vida = p1_vida + 1;
            printf("vidas do jogador 1: %d\n", p1_vida);
          }
        } else if (p1_position == 5 || p1_position == 12 || p1_position == 23) {
          // rolar dado novamente
          rolar_dado();
          p1_your_turn = 1;
          p2_your_turn = 0;
          printf("vidas do jogador 1: %d\n", p1_vida);
        } 
        else {
          p1_your_turn = 0;
          p2_your_turn = 1;
          printf("vidas do jogador 1: %d\n", p1_vida);
        }
      }
    }
    // JOGADOR 2
    if (p2_your_turn == 1) {

      if (p2_am == 1) {
        printf("Jogador 2 nao ira jogar\n");

        p1_your_turn = 0;
        p2_your_turn = 1;
        p1_am = 0;
        printf("vidas do jogador 2: %d\n", p2_vida);
      } else {
        
        printf("Vez do jogador 2, Role!\n");
        getc(stdin);
        
        printf("Dado: %d\n", dado = rolar_dado());
        p2_position = p2_position + dado;

        if (p2_position == 0 || p2_position == 12) {
          p2_position = 0;
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        }

        else if (p2_position == 2 || p2_position == 9 || p2_position == 15 ||               p2_position == 24) {
          p2_vida = p2_vida - 3;
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        }

        else if (p2_position == 7 || p2_position == 18 || p2_position == 26) {
          p2_am = 0;
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        }

        else if (p2_position == 3 || p2_position == 10 || p2_position == 17 || p2_position == 22 || p2_position == 27) {
          if (p2_vida < 10) {
            p2_vida = p2_vida + 1;
          }
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        } 
        
        else if (p2_position == 5 || p2_position == 12 || p2_position == 23) {
          // rolar dado novamente
          rolar_dado();
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        } 
        else {
          p2_your_turn = 0;
          p1_your_turn = 1;
          printf("vidas do jogador 2: %d\n", p2_vida);
        }
      }
    }

    tabuleiro(p1_position, p2_position);
  }
  if(p1_vida<=0)
    printf("O Jogador 1 morreu!\n");

  else if(p2_vida<=0)
    printf("O Jogador 2 morreu!\n");
  
  else if(p1_position>27)
    printf("O Jogador 1 venceu!\n");
  else if(p2_position>27)
    printf("O Jogador 2 venceu!\n");
  
  return 0;
}

