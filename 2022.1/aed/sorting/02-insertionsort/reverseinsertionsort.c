// ordem decrescente

#include <stdio.h>

int main()
{ 
  int arr[] = { 2, 3, 4, 5, 78, 12 };
  int size = sizeof(arr) / sizeof(arr[0]);
  int temp, j;

  for (int i = size-2; i > -1; i--) {
    temp = arr[i];
    j = i + 1;

    while (j <= size-1 && arr[j] > temp) {
      arr[j - 1] = arr[j];
      j++;
    }
    arr[j-1] = temp;
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}