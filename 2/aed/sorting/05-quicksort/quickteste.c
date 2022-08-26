/*
  1- partition deve guardar o pivot e o index do pivot, para cada A[j] <= pivot, index de pivot incrementa
  e é feita uma troca do elemento no index com elemento em j, após tudo, o elemento pivot vai para onde o index
  de pivot parou, então ele retorna o index do pivot

  2- quicksort se l < r então é chamada a funcçaõ partition para retornar o index do pivot, então 
  é chamado recursivamente quicksort(arr, l, pivot_index-1) e quicksort(arr, pivot_index+1, r)
*/

#include <stdio.h>

void printArr(int arr[], int size) 
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

int partition(int arr[], int l, int r)
{
  int pivot = arr[l];
  int pivot_index = l;

  for (int j = l + 1; j <= r; j++) {
    if (arr[j] <= pivot) {
      pivot_index++;
      swap(arr, pivot_index, j);
    }
  }

  swap(arr, l, pivot_index);
  return pivot_index;
}

void quicksort(int arr[], int l, int r)
{
  if (l < r) {
    int pivot_index = partition(arr, l, r);
    quicksort(arr, l, pivot_index - 1);
    quicksort(arr, pivot_index + 1, r);
  }
}

int main()
{ 
  int array[] = {4, 3, 2, 5, 6, 7, 0, 9, 8, 1};
  int size = sizeof(array) / sizeof(array[0]);

  printArr(array, size);
  
  quicksort(array, 0, 9);

  printArr(array, size);

  return 0;
}