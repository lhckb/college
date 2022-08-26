#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void randomlyFillArray(int arr[], int size)
{
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    arr[i] = rand()%101;
  }
}

void bubblesort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j+1);
      }
    }
  }
}

int main()
{
  const int size = 20;
  int array[size];
  
  randomlyFillArray(array, size);

  printArray(array, size);

  bubblesort(array, size);

  printArray(array, size);

  return 0;
}