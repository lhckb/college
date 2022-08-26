#include <stdio.h>

int main()
{
  for (int i = 0; i < 6; i++) {
    int count = i;
    for (int j = 0; j < 5; j++) {
      if (count > 0) {
        printf("0");
        count--;
      }
      else {
        printf("x");
      }
    }
    printf("\n");
  }

  return 0;
}