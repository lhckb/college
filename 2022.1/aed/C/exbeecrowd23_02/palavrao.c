#include <stdio.h>

int main()
{
  char word[21];
  int count = 0;

  scanf("%s", word);

  for (int i = 0; word[i] != '\0'; i++) {
    count ++;
  }

  if (count >= 10) {
    printf("palavrao\n");
  }
  else {
    printf("palavrinha\n");
  }

  printf("%d\n", count);

  return 0;
}