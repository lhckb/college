#include <stdio.h>

int array[] = {3, 4, 2, 1, 9, 8, 7};
// int size = sizeof(array) / sizeof(array[0]);
int finalArr[7];

void printArr(int arr[])
{
  //int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < 7; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], int left, int center, int right)
{
  int size = sizeof(arr) / arr[0];
  int leftArr[size / 2], rightArr[size/2], i = left, j = center + 1, k = 0;

  while (i < center && j < right) {
    if (leftArr[i] <= rightArr[j]) {
      finalArr[k] = leftArr[i];
      i++;
    }
    else {
      finalArr[k] = rightArr[j];
      j++;
    }
    k++;
  }
}

void mergesort(int arr[], int left, int right)
{
	if (left < right) {
		int center = left + (right - left) / 2;

		mergesort(arr, left, center);
		mergesort(arr, center+1, right);
		merge(arr, left, center, right);
	}
}

int main()
{
  // int array[] = {3, 4, 2, 1, 9, 8, 7};
  // int size = sizeof(array) / sizeof(array[0]);

  printArr(array);

  mergesort(array, 0, 6);

  printArr(finalArr);

  return 0;
}

