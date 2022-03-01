#include <stdio.h>
 
int main() {
 
    double r;
    
    scanf("%lf", &r);
    
    double result = ((r * r * r) * (4.0/3.0) * 3.14159);
    
    printf("VOLUME = %.3lf\n", result);
 
    return 0;
}