#include <stdio.h>

int main()
{
  int size, left = 0;

  printf("tamanho do quadrado: ");
  scanf("%i", &size);

  int right = size - 1;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (j == left) {
        printf("x");
      }
      else if (j == right) {
        printf("x");
      }
      else {
        printf(" ");
      }
    }
    left++;
    right--;
    printf("\n");
  }

  return 0;
}