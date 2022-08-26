#include <stdio.h>

void merge(int arr[], int l, int c, int r)
{
  int size_left = c - l + 1;
  int size_right = r - c;

  int left_aux[size_left];
  int right_aux[size_right];

  for (int i = 0; i < size_left; i++) {
    left_aux[i] = arr[l + i];
  }
  for (int j = 0; j < size_right; j++) {
    right_aux[j] = arr[c + 1 + j];
  }

  for (int i = 0, j = 0, k = l; k <= r; k++) {
    if ((i < size_left) && ((left_aux[i] <= right_aux[j]) || j >= size_right)) {
      arr[k] = left_aux[i];
      i++;
    }
    else {
      arr[k] = right_aux[j];
      j++;
    }
  }
} 

void mergesort(int arr[], int l, int r)
{
  if (l < r) {
    int center = l + (r - l) / 2;

    mergesort(arr, l, center);
    mergesort(arr, center+1, r);
    merge(arr, l, center, r); 
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
  int arr[] = {3, 4, 2, 1, 7, 6, 5, 8, 9, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArr(arr, size);

  mergesort(arr, 0, size-1);

  printArr(arr, size);

  return 0;
}