#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 8
int tab[SIZE][SIZE];

int jog1;
int jog2;

int linha, coluna, linha2, coluna2;

void zerar();
void inicializar_jog1();
void inicializar_jog2();
void escolha();
int jogador1();
int jogador2();
void imprimir();
int jogo();

void zerar()
{
    int i,j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            tab[i][j] = 0;
        }
    }
}

void inicializar_jog1()
{
    srand(time(NULL));
    int flag = 0;
    while(flag == 0){
        linha = rand()%8;
        coluna = rand()%8;
        if(tab[linha][coluna] == 0){
                tab[linha][coluna] = 1;
                flag = 1;
        }
    }
}

void inicializar_jog2()
{
    srand(time(NULL));
    int flag = 0;
    while(flag == 0){
        linha2 = rand()%8;
        coluna2 = rand()%8;
        if(tab[linha2][coluna2] == 0){
                tab[linha2][coluna2] = 2;
                flag = 1;
        }
    }
}

void escolha()
{
    // ESCOLHA DO 1 
    printf("Jogador 1\n");
    printf("----------------\n");
    printf("Torre = 1\n");
    printf("Bispo = 2\n");
    printf("Rainha = 3\n");
    printf("Rei = 4\n");
    printf("Cavalo = 5\n");
    printf("Peao = 6\n");
    printf("------------------\n");
    printf("escolha a sua pedra: ");
    scanf("%d", &jog1);
   
  // ESCOLHA DO 2 
    printf("Jogador 2\n");
    printf("----------------\n");
    printf("Torre = 1\n");
    printf("Bispo = 2\n");
    printf("Rainha = 3\n");
    printf("Rei = 4\n");
    printf("Cavalo = 5\n");
    printf("Peao = 6\n");
    printf("------------------\n");
    printf("escolha a sua pedra: ");
    scanf("%d", &jog2);
}

void imprimir()
{
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%i ", tab[i][j]);
        }
        printf("\n");
    }
}

int jogador1()
{
        // JOGADA DO 1
        int linha,coluna,morreu;
        switch(jog1){
            case 1: // torre
                // move em forma de +
                morreu = 0;
               
                for(linha=0; linha<8; linha++){
                    if(tab[linha][coluna] == 2){
                        morreu = 1;
                        return 1;
                    }else{
                        morreu = 0;
                        return 0;
                    }
                }
                for(coluna=0; coluna<8; coluna++){
                    if(tab[linha][coluna] == 2){
                        morreu = 1;
                        return 1;
                    }else{
                        morreu = 0;
                        return 0;
                    }
                }
                if(morreu == 0){
                    return 0;
                }
                break;
          
            case 2: // bispo
                // move em diagonais 
                morreu = 0;
              
                while(morreu==0){
                    //  l- c-
                    for(linha=0;linha<8;linha--){
                        for(coluna=0;coluna<8;coluna--){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            }
                        }
                    }
                    //  l+ c-
                    for(linha=0;linha<8;linha++){
                        for(coluna=0;coluna<8;coluna--){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            }  
                        }
                    }
                    //  l- c+
                    for(linha=0;linha<8;linha--){
                        for(coluna=0;coluna<8;coluna++){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    //  l+ c+
                    for(linha=0;linha<8;linha++){
                        for(coluna=0;coluna<8;coluna++){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    if(morreu == 0){
                        return 0;
                    }
                }
                break;
          
            case 3: // rainha
              //1 movimento para todos os lugares(mais e diagonais)
                morreu = 0;
                while(morreu==0){
                    //  l- c-
                    for(linha=0;linha<8;linha--){
                        for(coluna=0;coluna<8;coluna--){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            }
                        }
                    }
                    //  l+ c-
                    for(linha=0;linha<8;linha++){
                        for(coluna=0;coluna<8;coluna--){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            }  
                        }
                    }
                    //  l- c+
                    for(linha=0;linha<8;linha--){
                        for(coluna=0;coluna<8;coluna++){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    //  l+ c+
                    for(linha=0;linha<8;linha++){
                        for(coluna=0;coluna<8;coluna++){
                            if(tab[linha][coluna] == 2 || tab[linha][coluna] == 2){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    for(linha=0; linha<8; linha++){
                        if(tab[linha][coluna] == 2){
                            morreu = 1;
                            return 1;
                        }
                    }
                    for(int coluna=0; coluna<8; coluna++){
                        if(tab[linha][coluna] == 2){
                            morreu = 1;
                            return 1;
                        }
                    }
                    if(morreu == 0){
                        return 0;
                    }
                }
                break;

            case 4: // rei
                morreu = 0;
                // meio cima baixo
                if(tab[linha+1][coluna] == 2 || tab[linha-1][coluna] == 2){
                    morreu = 1;
                    return 1;
                  // linha baixo 
                }else if (tab[linha+1][coluna+1] == 2 || tab[linha+1][coluna-1] == 2){
                    morreu = 1;
                    return 1;
                  // linha cima
                }else if (tab[linha-1][coluna+1] == 2 || tab[linha-1][coluna-1] == 2){
                    morreu = 1;
                    return 1;
                  // linha meio 
                }else if (tab[linha][coluna+1] == 2 || tab[linha][coluna-1] == 2){
                    morreu = 1;
                    return 1;
                }else{
                    morreu = 0 ;
                    return 0;
                }
              //quadrado ao redor(uma casa)
                break;
          
            case 5: // cavalo
              // duas em + e uma pra esquerda ou direita
                morreu = 0;
                for(linha=0;linha<8;linha++){
                    for(coluna=0;coluna<8;coluna++){
                      // cima
                        if(tab[linha-2][coluna+1] == 2 || tab[linha-2][coluna-1] == 2){
                            morreu = 1;
                            return 1;
                      // baixo 
                        }else if (tab[linha+2][coluna+1] == 2 || tab[linha+2][coluna-1] == 2){
                            morreu = 1;
                            return 1;
                      // lado esq
                        }else if (tab[linha-1][coluna-2] == 2 || tab[linha+1][coluna-2] == 2){
                            morreu = 1;
                            return 1;
                      // lado dir
                        }else if (tab[linha-1][coluna+2] == 2 || tab[linha+1][coluna+2] == 2){
                            morreu = 1;
                            return 1;
                        }else{
                            morreu = 0;
                            return 0;
                        }
                    }
                }
                break;
    
            case 6: // peao
              // anda pra frente uma casa 
                morreu = 0;
                if(tab[linha+1][coluna-1] == 2 || tab[linha+1][coluna+1] == 2 ){
                    morreu = 1;
                    return 1;
                }else{
                  return 0;
                }
                break;
        }
        return 0;
}

int jogador2()
{
      //JOGADA DO 2
        int linha2,coluna2,morreu;
        switch(jog2){
            case 1: // torre
                morreu = 0;
                for(linha2=0; linha2<8; linha2++){
                    if(tab[linha2][coluna2] == 1){
                        morreu = 1;
                        return 1;
                    }else{
                        morreu = 0;
                        return 0;
                    }
                }
                for(coluna2=0; coluna2<8; coluna2++){
                    if(tab[linha2][coluna2] == 1){
                        morreu = 1;
                        return 1;
                    }else{
                        morreu = 0;
                        return 0;
                    }
                }
                if(morreu == 0){
                    return 0;
                }
                break;
          
           case 2: // bispo 
              // move em diagonais 
                morreu = 0;
              
                while(morreu==0){
                    //  l- c-
                    for(linha2=0;linha2<8;linha2--){
                        for(coluna2=0;coluna2<8;coluna2--){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            }
                        }
                    }
                    //  l+ c-
                    for(linha2=0;linha2<8;linha2++){
                        for(coluna2=0;coluna2<8;coluna2--){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            }  
                        }
                    }
                    //  l- c+
                    for(linha2=0;linha2<8;linha2--){
                        for(coluna2=0;coluna2<8;coluna2++){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    //  l+ c+
                    for(linha2=0;linha2<8;linha2++){
                        for(coluna2=0;coluna2<8;coluna2++){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    if(morreu == 0){
                          return 0;
                    }
                }
                break;
          
            case 3: //rainha
                morreu = 0;
                
                while(morreu==0){
                    //  l- c-
                    for(linha2=0;linha2<8;linha2--){
                        for(coluna2=0;coluna2<8;coluna2--){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            }
                        }
                    }
                    //  l+ c-
                    for(linha2=0;linha2<8;linha2++){
                        for(coluna2=0;coluna2<8;coluna2--){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            }  
                        }
                    }
                    //  l- c+
                    for(linha2=0;linha2<8;linha2--){
                        for(coluna2=0;coluna2<8;coluna2++){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    //  l+ c+
                    for(linha2=0;linha2<8;linha2++){
                        for(coluna2=0;coluna2<8;coluna2++){
                            if(tab[linha2][coluna2] == 1 || tab[linha2][coluna2] == 1){
                                morreu = 1;
                                return 1;
                            } 
                        }
                    }
                    for(linha2=0; linha2<8; linha2++){
                        if(tab[linha2][coluna2] == 1){
                            morreu = 1;
                            return 1;
                        }
                    }
                    for(coluna2=0; coluna2<8; coluna2++){
                        if(tab[linha2][coluna2] == 1){
                            morreu = 1;
                            return 1;
                        }
                    }
                    if(morreu == 0){
                        return 0;
                    }
                }
                break;
       
            case 4: // rei
                morreu = 0;
                // meio cima baixo
                if(tab[linha2+1][coluna2] == 1 || tab[linha2-1][coluna2] == 1){
                    morreu = 1;
                    return 1;
              // linha baixo 
                }else if (tab[linha2+1][coluna2+1] == 1 || tab[linha2+1][coluna2-1] == 1){
                    morreu = 1;
                    return 1;
              // linha cima
                }else if (tab[linha2-1][coluna2+1] == 1 || tab[linha2-1][coluna2-1] == 1){
                    morreu = 1;
                    return 1;
              // linha meio 
                }else if (tab[linha2][coluna2+1] == 1 || tab[linha2][coluna2-1] == 1){
                    morreu = 1;
                    return 1;
                }else{
                    morreu = 0;
                    return 0;
                }
                break;
          
            case 5: // cavalo
                morreu = 0;
              
                for(linha2=0;linha2<8;linha2++){
                    for(coluna2=0;coluna2<8;coluna2++){
                      // cima
                        if(tab[linha2-2][coluna2+1] == 1 || tab[linha2-2][coluna2-1] == 1){
                            morreu = 1;
                            return 1;
                      // baixo 
                        }else if (tab[linha2+2][coluna2+1] == 1 || tab[linha2+2][coluna2-1] == 1){
                            morreu = 1;
                            return 1;
                      // lado esq
                        }else if (tab[linha2-1][coluna2-2] == 1 || tab[linha2+1][coluna2-2] == 1){
                            morreu = 1;
                            return 1;
                      // lado dir
                        }else if (tab[linha2-1][coluna2+2] == 1 || tab[linha2+1][coluna2+2] == 1){
                            morreu = 1;
                            return 1;
                        }else{
                            morreu = 0;
                            return 0;
                        }
                    }
                }
                if(morreu == 0){
                    return 0;
                }
                break;
          
            case 6: //peao
                morreu = 0;
                if(tab[linha2-1][coluna2-1] == 2 || tab[linha2-1][coluna2+1] == 2 ){
                    morreu = 1;
                    return 1;
                }else{
                  return 0;
                }
                break;
        }
        return 0;
}

int jogo()
{
  if (jogador1() == 1){
    printf("jogador 2 morreu");
  }else if(jogador2() == 1){
    printf("jogador 1 morreu");
  }else{
    printf("nenhum jogador morreu");
  }
  return 0;
}

int main()
{
    zerar();
    inicializar_jog1();
    inicializar_jog2();
    escolha();
    imprimir();
    jogador1();
    jogador2();
    jogo();

    return 0;
}
