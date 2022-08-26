#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomlyFillArray(int arr[], int size)
{
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    arr[i] = rand()%101;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}

void swap(int arr[], int pos1, int pos2)
{
  int temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

void selectionsort(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    int smallest_idx = i;

    for (int j = i; j < size; j++) {
      if (arr[j] < arr[smallest_idx]) {
        smallest_idx = j;
      }
    }

    swap(arr, i, smallest_idx);
  } 
}

int main()
{
  const int size = 20;
  int array[size];

  randomlyFillArray(array, size);

  printArray(array, size);

  selectionsort(array, size);

  printArray(array, size);

  return 0;
}