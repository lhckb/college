// ordem decrescente

#include <stdio.h>

void swapElements(int arr[], int pos1, int pos2)
{
  int temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp; 
}

int main()
{
  int arr[] = { 2, 4, 1, 5, 9, 10, 21 };
  int size = sizeof(arr) / sizeof(arr[0]);

  for (int i = size-1; i > -1; i--) {
    for (int j = size-1; j > 0; j--) {
      if (arr[j] > arr[j-1]) {
        swapElements(arr, j, j-1);
      }
    }
  }

  for (int x = 0; x < size; x++) {
    printf("%d ", arr[x]);
  }

  return 0;
}