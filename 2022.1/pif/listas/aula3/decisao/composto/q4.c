#include <stdio.h>

int main()
{
  float grade1, grade2, grade3;

  printf("type in the three grades: ");
  scanf("%f %f %f", &grade1, &grade2, &grade3);

  float res = (grade1 + grade2 + grade3) / 3;

  if (res >= 7) {
    printf("voce passou\n");
  }
  else {
    printf("voce nao passou\n");
  }

  return 0;
}