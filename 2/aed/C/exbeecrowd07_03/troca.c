#include <stdio.h>
 
int main() {
 
    int N[20];
    
    for (int i = 0; i < 20; i++) {
        scanf("%i", &N[i]);
    }
    
    int temp, rev_count = 19;
    for (int j = 0; j < 10; j++) {
        temp = N[j];
        N[j] = N[rev_count];
        N[rev_count] = temp;
        rev_count--;
    }
    
    for (int x = 0; x < 20; x++) {
        printf("N[%i] = %i\n", x, N[x]);
    }
 
    return 0;
}