// ordem crescente

#include <stdio.h>

void swapElements(int* arr, int pos1, int pos2)
{
  int temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

int main() 
{
  int nums[] = { 3, 5, 4, 8, 2 };
  int size = sizeof(nums) / sizeof(nums[0]);
  int smallest_idx;

  for (int i = 0; i < size; i++) {
    smallest_idx = i;
    for (int j = i+1; j < size; j++) {
      if (nums[j] < nums[smallest_idx]) {
        smallest_idx = j;
      }
    }
    swapElements(nums, smallest_idx, i);
  }

  for (int x = 0; x < size; x++) {
    printf("%d ", nums[x]);
  }

  return 0;
}