#include <stdio.h>
 
int main() {
int hora;
int velo_med;
float result;
float result2;
int result3;
scanf("%d", hora);
scanf("%d", velo_med);
result = hora * velo_med;
result2 = result / 12;
printf("%.3f\n",result2);
    return 0;
}