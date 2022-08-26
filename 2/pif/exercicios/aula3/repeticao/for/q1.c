#include <stdio.h>

int main()
{
  int nums[10], count = 0, sum = 0;

  for (int i = 0; i < 10; i++) {
    scanf("%i", &nums[i]);
  }

  for (int j = 0; j < 10; j++) {
    if (nums[j] >= 0) {
      sum += nums[j];
      count++;
    }
  }

  float res = (float)sum / count;

  printf("a média é: %.2f\n", res);

  return 0;
}