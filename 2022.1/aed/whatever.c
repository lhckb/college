#include <stdio.h>
#include <math.h>

void selectionsort(int matricula[5], float mediatotal[5]){
        for(int i=0;i<5-1;i++){
            int maior = i;
            for(int j=i+1;j<5;j++){
                    if(mediatotal[j]>mediatotal[maior]){
                            maior = j;
                    }
            }
            float aux = mediatotal[maior];
            mediatotal[maior] = mediatotal[i];
            mediatotal[i] = aux;
                
            int aux2 = matricula[maior];
            matricula[maior] = matricula[i];
            matricula[i] = aux2;
            
            for(int i = 0; i < 5; i++){
                if(i == 0){
                    printf("%d %.2f Classificado\n", matricula[0], mediatotal[0]);
                }else if(i == 1){
                    printf("%d %.2f Aprovado\n", matricula[1], mediatotal[1]);
                }else if(i ==2){
                    printf("%d %.2f Aprovado\n", matricula[2], mediatotal[2]);
                }else if(i == 3){
                    printf("%d %.2f Aprovado\n", matricula[3], mediatotal[3]);
                }else {
                    printf("%d %.2f Reprovado\n", matricula[4], mediatotal[4]);
                }
            }
        
        }
}


int main(){
        int acesso;
        float n1,n2,n3,n4,media;
        int matricula[5];
        float mediatotal[5];

        for(int i=0;i<5;i++){
                scanf("%d %f %f %f %f",&acesso, &n1,&n2,&n3,&n4);
                matricula[i] = acesso;
                media = (n1+n2+n3+n4)/4;
                media = floor(media*100.0f)/100.0f;
                mediatotal[i] = media;
                
        }
        selectionsort(matricula, mediatotal);

        return 0;
}