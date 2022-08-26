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

void merge(int arr[], int left, int center, int right)
{
  // auxiliary arrays
  int left_length = center - left + 1;
  int right_length = right - center;
  int left_aux[left_length];
  int right_aux[right_length];

  for (int i = 0; i < left_length; i++) {
    left_aux[i] = arr[left + i];
  }
  for (int i = 0; i < right_length; i++) {
    right_aux[i] = arr[center + 1 + i];
  } 

  for (int i = 0, j = 0, k = left; k < right+1; k++) {
    if ((i < left_length) && (left_aux[i] < right_aux[j] || j >= right_length)) {
      arr[k] = left_aux[i];
      i++;
    }
    else {
      arr[k] = right_aux[j];
      j++;
    }
  }
}

void mergesortRecursion(int arr[], int left, int right)
{
  if (left < right) {
    int center = left + (right - left) / 2;

    mergesortRecursion(arr, left, center);
    mergesortRecursion(arr, center + 1, right);
    merge(arr, left, center, right);
  }
}

int main()
{
  const int size = 20;
  int array[size];

  randomlyFillArray(array, size);

  printArray(array, size);

  mergesortRecursion(array, 0, size-1);

  printArray(array, size);

  return 0;
}