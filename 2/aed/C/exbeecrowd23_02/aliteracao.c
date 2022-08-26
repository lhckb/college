#include <stdio.h>
#include <ctype.h>

int main() 
{
  char sentence[6001];
  char initials[101];
  int strLen = 0, index = 1, count = 0;

  while(scanf(" %[^\n]", sentence) != EOF) {

    for (int i = 0; sentence[i] != '\0'; i++) {
      strLen = i + 1;
    }

    initials[0] = sentence[0];

    for (int j = 0; j < strLen; j++) {
      if (sentence[j] == ' ') {
        initials[index] = sentence[j + 1];
        index++;
      }
    }

    for (int x = 0; x < index; x++) {
      initials[x] = tolower(initials[x]);
    }

    for (int k = 0; k < index; k++) {
      if ((k == 0) && (initials[k] == initials[k+1])) {
        count++;
      }
      else if ((initials[k] == initials[k + 1]) && (initials[k] != initials[k-1])) {
        count ++;
      }
    }

    printf("%d\n", count);

    count = 0;
    index = 1;
    strLen = 0;
  }

  return 0;
}