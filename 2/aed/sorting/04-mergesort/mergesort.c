#include <stdio.h>

/* 
  1- setar a função recursiva, recursao para quando l >= r, obtem o centro depois 
  faz recursão para seções esquerda e direita, depois chama merge passando array, esquerda, centro e direita

  2- implementa o merge, seta os arrays auxiliares e atribui a eles os valores correspondentes
  no array base

  3- dentro do procedimento merge, implementa o merge de fato, onde o array base vai receber dos auxiliares
  os valores correspondentes até que k atinga o index final r.
  se i estiver dentro do tamanho do array esquerdo e r ja tiver acabado ou l[i] < r[j], arr[k] = l[i]
  senão, arr[k] = r[j]
*/

void merge(int arr[], int left, int center, int right)
{
  int left_length = center - left + 1;
  int right_length = right - center;

  int temp_left[left_length];
  int temp_right[right_length];

  // putting left values on aux array
  for (int i = 0; i < left_length; i++) {
    temp_left[i] = arr[left + i];
  }

  // putting right values on aux array
  for (int j = 0; j < right_length; j++) {
    temp_right[j] = arr[center + 1 + j];
  }

  int i, j, k;
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

void mergesort(int arr[], int left, int right)
{
  if (left < right) {
    int center = left + (right - left) / 2;
    
    mergesort(arr, left, center);
    mergesort(arr, center + 1, right);

    merge(arr, left, center, right);
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
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6 };
  int length = 10;

  printArr(array, length);

  mergesort(array, 0, length - 1);

  printArr(array, length);

  return 0;
}
