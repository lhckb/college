#include <stdio.h>

void mergesort(int arr[], int length);
void mergesortRecursion(int arr[], int left, int right);
void mergeSortedArrays(int arr[], int left, int center, int right);

int main()
{
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6 };
  int length = 10;

  mergesort(array, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

void mergesort(int arr[], int length) 
{
  mergesortRecursion(arr, 0, length-1);
}

void mergesortRecursion(int arr[], int left, int right)
{
  if (left < right) {
    int center = left + (right - left) / 2;
    
    mergesortRecursion(arr, left, center);
    mergesortRecursion(arr, center + 1, right);

    mergeSortedArrays(arr, left, center, right);
  }
}

void mergeSortedArrays(int arr[], int left, int center, int right)
{
  int left_length = center - left + 1;
  int right_length = right - center;

  int temp_left[left_length];
  int temp_right[right_length];

  int i, j, k;

  for (int i = 0; i < left_length; i++) {
    temp_left[i] = arr[left + i];
  }

  for (int i = 0; i < right_length; i++) {
    temp_right[i] = arr[center + 1 + i];
  }

  for (i = 0, j = 0, k = left; k <= right; k++) {
    if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j])) {
      arr[k] = temp_left[i];
      i++;
    } 
    else {
      arr[k] = temp_right[j];
      j++;
    }
  }
}