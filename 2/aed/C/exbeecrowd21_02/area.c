#include <stdio.h>
 
int main() 
{
 
    double a, b, c;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double circulo = (c * c) * 3.14159;
    
    printf("TRIANGULO: %.3f\n", (a * c) / 2);
    printf("CIRCULO: %.3f\n", circulo);
    printf("TRAPEZIO: %.3f\n", (a + b) * c / 2);
    printf("QUADRADO: %.3f\n", b * b);
    printf("RETANGULO: %.3f\n", a * b);
 
    return 0;
}