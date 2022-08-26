#include <stdio.h>

int main()
{
  int time, avgSpeed;
  const int kmPerLiter = 12;

  scanf("%d \n %d", &time, &avgSpeed);

  int distance = time * avgSpeed;
  float liters = (float)distance / kmPerLiter;

  printf("%.3f\n", liters);

  return 0;
}