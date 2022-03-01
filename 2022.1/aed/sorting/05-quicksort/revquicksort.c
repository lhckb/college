#include <stdio.h>

int arr[6] = {3, 2, 4, 6, 3, 9};

void swapElements(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

void quicksort(int start, int end)
{
  if (start >= end) {
    return;
  }
  int pivot = start, left = start + 1, right = end; // indices

  while (left <= right) {

    while (left <= end && arr[left] >= arr[pivot]) {
      left++;
    }

    while (right > start && arr[right] <= arr[pivot]) {
      right--;
    }

    if (left > right) {
      swapElements(&arr[pivot], &arr[right]);
    }
    else {
      swapElements(&arr[left], &arr[right]);
    }
  }
  quicksort(start, right-1);
  quicksort(right + 1, end);
}

int main()
{
  printArr(arr, 6);
  printf("\n");
  quicksort(0, 5);
  printArr(arr, 6);
  printf("\n");

  return 0;
}