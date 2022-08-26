#include <stdio.h>

void swap(int arr[], int pos1, int pos2)
{
  int temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

int partition(int arr[], int l, int r)
{
  int pivot = arr[l];
  int i = l;

  for (int j = l + 1; j < r; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr, i, j);
    }
  }

  swap(arr, l, i);
  return i;
}

void quicksort(int arr[], int l, int r)
{
  if (l < r) {
    int pivot_index = partition(arr, l, r);
    quicksort(arr, l, pivot_index - 1);
    quicksort(arr, pivot_index + 1, r);
  }
}

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int array[] = {3, 2, 1, 7, 6, 5, 4, 9, 0, 8};
  int size = sizeof(array) / sizeof(array[0]);

  printArr(array, size);

  quicksort(array, 0, 9);

  printArr(array, size);

  return 0;
}