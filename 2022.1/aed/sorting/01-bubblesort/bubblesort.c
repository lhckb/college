// ordem crescente

#include <stdio.h>

void switchElements(int* array, int pos1, int pos2)
{
  int temp = array[pos1];
  array[pos1] = array[pos2];
  array[pos2] = temp;
}

int main() 
{
  const int SIZE = 8;
  int arr[] = {4, 2, 3, 7 ,5, 120, 10, 6};

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE-1; j++) {
      if (arr[j] > arr[j+1]) {
        switchElements(arr, j, j+1);
      }
    }
  }

  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}