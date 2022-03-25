#include <stdio.h>
#include <string.h>
 
int main() {
    
  char input[1000];
  int data[1000];
  int count = 0;

  while(scanf(" %[^\n]", input) != EOF) {

    if (input[0] == 'P' && input[0] != '1') {
      for (int i = 0; i < 12; i++) {
        if (input[i] == ' ') {
          data[count] = ((input[i+1]-48)*100) + ((input[i+2]-48)*10) + ((input[i+3]-48));
        }
      }
      count++;
    }

    if (input[0] == '0') {

      for (int i = 0; i < count; i++) {
        int j = i;
        while (j > 0 && data[j] < data[j-1]) {
          int temp = data[j];
          data[j] = data[j-1];
          data[j-1] = temp;
          j--;
        }
      }

      for (int k = 0; k < count; k++) {
        if (data[k] < 10) {
          printf("Package 00%i\n", data[k]);
        }
        else if (data[k] < 100) {
          printf("Package 0%i\n", data[k]);
        }
        else {
          printf("Package %i\n", data[k]);
        }
      }

      printf("\n");

      count = 0;
    }
  }

  return 0;
}