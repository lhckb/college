#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}

int partition(int arr[], int left, int right) 
{
  int pivot = arr[left];
  int pivot_index = left;

  for (int i = left+1; i <= right; i++) {
    if (arr[i] < pivot) {
      pivot_index++;
      swap(arr, pivot_index, i);
    }
  }
  swap(arr, pivot_index, left);
  return pivot_index;
}

void quicksort(int array[], int left, int right)
{
  if (left < right) {
    int pivot_index = partition(array, left, right);
    quicksort(array, left, pivot_index - 1);
    quicksort(array, pivot_index + 1, right);
  }
}

int main()
{
  const int size = 20;
  int array[size];

  randomlyFillArray(array, size);

  printArray(array, size);

  quicksort(array, 0, size-1);

  printArray(array, size);

  return 0;
}