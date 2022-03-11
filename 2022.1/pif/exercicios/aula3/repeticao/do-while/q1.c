#include <stdio.h>

int main()
{
  int nums = 0, input;

  do {
    scanf("%i", &input);
    if (input >= 0) {
      nums += input;
    }
  } while (input >= 0);

  printf("soma dos positivos: %i\n", nums);

  return 0;
}