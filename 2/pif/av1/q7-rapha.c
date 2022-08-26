#include <stdio.h>

int main() {
    
    int contadoring = 0;
    while(contadoring<8){
    
            //início e quantidade de ingressos que o usuario deseja
                int quant_ingressos;
                printf("  ------------------------------------ \n");
                printf(" Seja bem-vindo ao cinema da Cesar School ");
                printf("\n  ------------------------------------ \n");  
                printf("\nQuantos ingressos você deseja?\n");
                scanf("%d", &quant_ingressos);
            
            //tipo do ingresso
                if(quant_ingressos == 1){
                    contadoring++;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    int ingressosresultado1;
                    printf("\nOs ingressos custam: ");
                    printf("\nInteira: R$20,00 "); 
                    printf("\nMeia Entrada: R$10,00\n");
                    printf("--------------------------------");                            
                    printf("\nDigite '1' para inteira e '2' para meia entrada\n");
                    printf("\n ME CONTE SEU DESEJO =) ?  ");
        
                        scanf("%d", &ingressosresultado1 );
                            if (ingressosresultado1 == 1){
                                printf("\nVoce comprou 1 inteira");
                                printf("\nE gastou 20 reais"); 
                                    }else{
                                        printf("\nVoce comprou 1 meia entrada");
                                        printf("\nE gastou 10 reais");
                                    }
        
            //escolher lugar no cinema   
                    printf("\nAgora vamos escolher seu lugar no cinema  ");
                    int lin = 3, col = 3, xLin, yCol;
                    int cadeiras[lin][col];
                    printf("\nOs lugares disponiveis sao = \n ");
                    printf("\n");
                    
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);  
                        }
                        printf("\n");
                    }
                    
                    printf("\n");
                    printf("insira as coordenadas para demarcar seu lugar: ");
                    scanf("%d %d", &xLin, &yCol);
                    
                    cadeiras [xLin][yCol] = 1;
                    
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [xLin][yCol] = 1;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                }else if (quant_ingressos == 2){
                    contadoring+=2;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                    int contador = 0;
                    int lin = 3, col = 3, xLin, yCol,xLin2,yCol2;
                    int cadeiras[lin][col];
        
                    printf("\nOs ingressos custam: "); 
                    printf("\nInteira: R$20,00\n");
                    printf("\nMeia: R$10,00\n");
                    printf("--------------------------------");
                    printf("\nDigite '1' para inteira e '2' para meia e '3' para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, você adquiriu 2 inteiras");
                                printf("\ne gastou 40 reais");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 2 meias");
                                    printf("\ne gastou 20 reais");
                                }else if(aux == 3){
                                    printf("\nParabens, voce adquiriu 1 meia e 1 inteira");
                                    printf("\ne gastou 30 reais");
                                   }
            //visualizar locais disponíveis
                    printf("\nOs lugares disponiveis sao = \n ");
                    printf("\n");
                    
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                    }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }    
        
                }else if (quant_ingressos == 3){
                    contadoring+=3;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                    printf("\nA inteira custa: R$20,00"); 
                            printf("\nMeia entrada: R$10,00\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 3 inteiras");
                                printf("\n E gastou 60 reias");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 3 meias");
                                    printf("\n E gastou 30 reias");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 2 inteiras");
                                        printf("\n E gastou 50 reias");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 1 inteira");
                                            printf("\n E gastou 40 reias");
                                        }
                                }        
        
                    int contador = 0;
                    int lin = 3, col = 3, xLin, yCol,xLin2,yCol2;
                    int xLin3, yCol3;
                    int cadeiras[lin][col];
                    printf("\nOs lugares disponíveis são = \n ");
                    printf("\n");
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                        }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }   
        
                }else if( quant_ingressos == 4){
                    contadoring+=4;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                    printf("\nA inteira custa R$20,00"); 
                            printf("\nA meia entrada custa R$10,00\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 3 inteiras");
                                printf("\nE gastou 80 reais");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 3 meias");
                                    printf("\nE gastou 40 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 3 inteiras");
                                        printf("\nE gastou 70 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 2 inteiras");
                                            printf("\nE gastou 60 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 1 inteira");
                                            printf("\nE gastou 50 reais");
                                        }
                                }     
                    int contador = 0;
                    int lin = 3, col = 3, xLin, yCol;
                    int cadeiras[lin][col];
                    printf("\nOs lugares disponiveis sao = \n ");
                    printf("\n");
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                        }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }   
        
                }else if(quant_ingressos == 5){
                    contadoring+=5;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                    printf("\nOs ingressos custam: R$20,00"); 
                            printf("\nMeia entrada custa: R$10,00 \n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 5 inteiras");
                                printf("\n E gastou 100 reias");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 5 meias");
                                    printf("\nE gastou 50 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabéns, voce adquiriu 1 meia e 3 inteiras");
                                        printf("\nE gastou 100 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 3 inteiras");
                                            printf("\nE gastou 80 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 2 inteiras");
                                            printf("\nE gastou 70 reais");
                                        }else if( aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 1 inteira");
                                            printf("\nE gastou 60 reais");
                                        }
                                }            
        
                    int lin = 3, col = 3, xLin, yCol;
                    int cadeiras[lin][col];
                    int contador = 0;
                    printf("\nOs lugares disponíveis são = \n ");
                    printf("\n");
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                        }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }   
        
                }else if(quant_ingressos == 6){
                    contadoring+=6;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                    printf("\nOs ingressos custam: R$20,00"); 
                            printf("\nA meia entrada custa: R$10,00\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 6 inteiras");
                                printf("\nE gastou 120 reais");
        
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 6 meias");
                                    printf("\nE gastou 60 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 5 inteiras");
                                        printf("\nE gastou 110 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 3 inteiras");
                                            printf("\nE gastou 100 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 3 inteiras");
                                            printf("\nE gastou 90 reais");
                                        }else if( aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 2 inteiras");
                                            printf("\nE gastou 80 reais");
                                        }else if(aux2 == 5){
                                            printf("\nParabens voce adquiriu 5 meias e 1 inteira");
                                            printf("\nE gastou 70 reais");
                                        }
                                }    
                    int lin = 3, col = 3, xLin, yCol;
                    int contador = 0;
                    int cadeiras[lin][col];
                    printf("\nOs lugares disponiveis sao = \n ");
                    printf("\n");
                    
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                        }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }   
                    
        
                }else if(quant_ingressos == 7){
                    contadoring+=7;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
        
                    printf("\nOs ingressos custam 20 reais"); 
                            printf("\na meia entrada cusa 10 reias\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 7 inteiras");
                                printf("\nE gastou 140 reais");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 7 meias");
                                    printf("\nE gastou 70 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 6 inteiras");
                                        printf("\nE gastou 130 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 5 inteiras");
                                            printf("\nE gastou 120 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 3 inteiras");
                                            printf("\nE gastou 110 reais");
                                        }else if( aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 3 inteiras");
                                            printf("\nE gastou 100 reais");
                                        }else if(aux2 == 5){
                                            printf("\nParabens voce adquiriu 5 meias e 2 inteiras");
                                            printf("\nE gastou 90 reais");
                                        }else if (aux2 == 6){
                                            printf("\nParabens voce adquiriu 6 meias e 1 inteira");
                                            printf("\nE gastou 80 reais");
                                        }
                                    }    
        
                    int lin = 3, col = 3, xLin, yCol;
                    int contador = 0;
                    int cadeiras[lin][col];
            
                    printf("\nOs lugares disponiveis sao = \n ");
                    printf("\n");
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            cadeiras [i][j] = 0 ;
                            printf("%i ", cadeiras[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    while(contador < quant_ingressos){
                            printf("\ninsira as coordenadas para demarcar seu lugar: ");
                            scanf("%d %d", &xLin, &yCol);
                            if(cadeiras[xLin][yCol]== 0){     
                                cadeiras [xLin][yCol] = 1;
                                contador++;
                            }else{
                                printf("\nCadeira ocupada\n");
                            }
                            
                        }
        
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                
                            printf("%i ", cadeiras[i][j]);
                            
                        }
                        printf("\n");
                    }   
        
        
                }else if (quant_ingressos == 8){
                    contadoring+=8;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                    
                        printf("\nOs ingressos custam 20 reais"); 
                            printf("\na meia entrada cusa 10 reias\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 8 inteiras");
                                printf("\nE gastou 160 reais");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 8 meias\n");
                                    printf("\nE gastou 80 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 7 inteiras");
                                        printf("\nE gastou 150 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 6 inteiras");
                                            printf("\nE gastou 140 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 5 inteiras");
                                            printf("\nE gastou 130 reais");
                                        }else if( aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 3 inteiras");
                                            printf("\nE gastou 120 reais");
                                        }else if(aux2 == 5){
                                            printf("\nParabens voce adquiriu 5 meias e 3 inteiras");
                                            printf("\nE gastou 110 reais");
                                        }else if (aux2 == 6){
                                            printf("\nParabens voce adquiriu 6 meias e 2 inteiras");
                                            printf("\nE gastou 100 reais");
                                        }else if (aux2 == 7){
                                            printf("\nParabens voce adquiriu 7 meias e 1 inteira");
                                            printf("\nE gastou 90 reais");
                                        }
                                }             
        
                            int lin = 3, col = 3, xLin, yCol;
                            int cadeiras[lin][col];
                            int contador = 0;
                            printf("\nOs lugares disponiveis sao = \n ");
                            printf("\n");
                            
                            for(int i = 0; i < 3; i++){
                                for(int j = 0; j < 3; j++){
                                    cadeiras [i][j] = 0 ;
                                    printf("%i ", cadeiras[i][j]);
                                }
                                printf("\n");
                            }
                            printf("\n");
                            
                            while(contador < quant_ingressos){
                                    printf("\ninsira as coordenadas para demarcar seu lugar: ");
                                    scanf("%d %d", &xLin, &yCol);
                                    if(cadeiras[xLin][yCol]== 0){     
                                        cadeiras [xLin][yCol] = 1;
                                        contador++;
                                    }else{
                                        printf("\nCadeira ocupada\n");
                                    }
                                    
                                }
        
                            for(int i = 0; i < 3; i++){
                                for(int j = 0; j < 3; j++){
                        
                                    printf("%i ", cadeiras[i][j]);
                                    
                                }
                                printf("\n");
                                }
        
        
                }else if (quant_ingressos == 9){
                    contadoring+=9;
                    printf("Foi selecionado: %d ingresso(s)", contadoring);
                
                        printf("\nOs ingressos custam 20 reais"); 
                            printf("\na meia entrada cusa 10 reias\n");
                            printf("--------------------------------");
                            printf("\nDigite 1 para inteira e 2 para meia e 3 para ambas = ");
        
                            int aux,ingressos3;
                            scanf("%i", &aux);
                            if (aux ==1){
                                printf("\nMuito bem, voce adquiriu 8 inteiras");
                                printf("\nE gastou 160 reais");
                                }else if(aux == 2){
                                    printf("\nMuito bem, voce adquiriu 8 meias\n");
                                    printf("\nE gastou 80 reais");
                                }else if(aux == 3){
                                    printf("Quantas meias ? ");
                                    int aux2;
                                    scanf("%d", &aux2);
                                    getchar();
                                    if (aux2 == 1){
                                        printf("\nParabens, voce adquiriu 1 meia e 7 inteiras");
                                        printf("\nE gastou 150 reais");
                                        }else if (aux2 == 2){
                                            printf("\nParabens voce adquiriu 2 meias e 6 inteiras");
                                            printf("\nE gastou 140 reais");
                                        }else if (aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 5 inteiras");
                                            printf("\nE gastou 130 reais");
                                        }else if( aux2 == 3){
                                            printf("\nParabens voce adquiriu 3 meias e 3 inteiras");
                                            printf("\nE gastou 120 reais");
                                        }else if(aux2 == 5){
                                            printf("\nParabens voce adquiriu 5 meias e 3 inteiras");
                                            printf("\nE gastou 110 reais");
                                        }else if (aux2 == 6){
                                            printf("\nParabens voce adquiriu 6 meias e 2 inteiras");
                                            printf("\nE gastou 100 reais");
                                        }else if (aux2 == 7){
                                            printf("\nParabens voce adquiriu 7 meias e 1 inteira");
                                            printf("\nE gastou 90 reais");
                                        }else if (aux2 == 8){
                                            printf("\nParabens voce adquiriu 8 meias e 1 inteira");
                                            printf("\nE gastou 100 reais");
                                        }
                                }
                         int lin = 3, col = 3, xLin, yCol;
                            int cadeiras[lin][col];
                            int contador = 0;
                            printf("\nOs lugares disponiveis sao = \n ");
                            printf("\n");
                            
                            for(int i = 0; i < 3; i++){
                                for(int j = 0; j < 3; j++){
                                    cadeiras [i][j] = 0 ;
                                    printf("%i ", cadeiras[i][j]);
                                }
                                printf("\n");
                            }
                            printf("\n");
                            while(contador < quant_ingressos){
                                    printf("\nInsira as coordenadas para demarcar seu lugar: ");
                                    scanf("%d %d", &xLin, &yCol);
                                    if(cadeiras[xLin][yCol]== 0){     
                                        cadeiras [xLin][yCol] = 1;
                                        contador++;
                                    }else{
                                        printf("\nCadeira ocupada\n");
                                    }
                                    
                                }
        
                            for(int i = 0; i < 3; i++){
                                for(int j = 0; j < 3; j++){
                        
                                    printf("%i ", cadeiras[i][j]);
                                    
                                }
                                printf("\n");
                            }
                            printf ("A sessão está lotada! Obrigado por comprar no Cinema Cesar, volte sempre Pericles!");
                  }
        }
  return 0;
}