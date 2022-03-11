#include <stdio.h>

int main()
{
  int n;

  printf("provenha um numero maior que 0: ");
  scanf("%i", &n);

  int nums[n];

  for (int i = 0; i < n; i++) {
    printf("digite um numero: ");
    scanf("%i", &nums[i]);
  }

  for (int i = 0; i < n; i++) {
    int multiplicado = nums[i];
    int num = nums[i];

    do {
      multiplicado = multiplicado * --nums[i];

    } while (nums[i] > 1);

    printf("fatorial de %i é %i\n", num, multiplicado);
  }

  return 0;
}