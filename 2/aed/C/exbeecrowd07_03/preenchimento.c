#include <stdio.h>
 
int main() {
 
    int N[10], V;
    
    scanf("%i", &V);
    
    N[0] = V;
    
    for (int i = 1; i < 10; i++) {
        N[i] = N[i-1] * 2;
    }
    
    for (int j = 0; j < 10; j++) {
        printf("N[%i] = %i\n", j, N[j]);
    }
 
    return 0;
}