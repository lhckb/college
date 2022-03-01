// ordem crescente

#include <stdio.h>

int main()
{
  int nums[] = { 12, 11, 13, 5, 6 };
  int size = sizeof(nums) / sizeof(nums[0]);
  int j, temp, count = 0;

  for (int i = 1; i < size; i++) {
    temp = nums[i];
    j = i-1;

    while (j >= 0 && nums[j] > temp) {
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = temp;
    count++;
  }

  printf("num of iterations: %d\n", count);

  for (int i = 0; i < size; i++) {
    printf("%d ", nums[i]);
  }

  printf("\n");

  return 0;
}