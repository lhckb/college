#include <stdio.h>

int main()
{
  int input = 1, count = 0, max, min, sum = 0, evens = 0, count_evens = 0;
  int condition = 1;

  while (condition) {
    printf("digite um numero (0 para parar): ");
    scanf("%i", &input);

    if (input == 0) {
      condition = 0;

    } else {
      if (count == 0) {
        max = input;
        min = input;
      }
      else if (input > max) {
        max = input;
      }
      else if (input < min) {
        min = input;
      }

      if (input % 2 == 0) {
        evens += input;
        count_evens++;
      }

      sum += input;

      count++;
    }
  }

  printf("soma de todos: %i\n", sum);
  printf("quantidade de números: %i\n", count);
  printf("média dos números digitados: %.3f\n", (float)sum / count);
  printf("maior numero: %i\n", max);
  printf("menor numero: %i\n", min);
  printf("média dos pares: %.3f\n", (float)evens / count_evens);

  return 0;
}