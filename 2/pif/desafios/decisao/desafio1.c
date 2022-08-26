#include <stdio.h>
#include <math.h>

int main()
{
  // distancia entre dois pontos d² = (x2-x1)² + (y2-y1)²
  float r, c1, c2, p1, p2;

  printf("digite o raio: ");
  scanf("%f", &r);

  printf("digite o x do centro: ");
  scanf("%f", &c1);

  printf("digite o y do centro: ");
  scanf("%f", &c2);

  printf("digite o x do ponto: ");
  scanf("%f", &p1);

  printf("digite o y do ponto: ");
  scanf("%f", &p2);

  float dist = sqrt(pow((p1-c1), 2) + pow((p2-c2), 2));

  if (dist <= r) {
    printf("está dentro\n");
  }
  else {
    printf("está fora\n");
  }

  return 0;
}