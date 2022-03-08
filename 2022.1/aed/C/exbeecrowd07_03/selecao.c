#include <stdio.h>
 
int main() {
 
  float A[5];
  
  for (int i = 0; i < 5; i++) {
    scanf("%f", &A[i]);
  }
  
  for (int j = 0; j < 5; j++) {
    if (A[j] <= 10) {
      printf("A[%i] = %.1f\n", j, A[j]);
    }
  }

  return 0;
}