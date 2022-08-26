#include <stdio.h>

// TESTANDO OUTPUT

int main() 
{
  char line[200000];
  int k, strLen = 0, count = 0;

  scanf("%s", line);

  for (int i = 0; line[i] != '\0'; i++) {
    strLen++;
  }

  for (int i = 1; i <= strLen; i++) {
    for (int j = 0; i <= strLen-i; j++) {
      k = i + strLen - 1;
      for (int x = i; k <= j; k++) {
        count ++;
      }
    }
  }

  printf("%d", count);

  return 0;
}