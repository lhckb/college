#include <stdio.h>
#include <ctype.h>

int main()
{
  char letter;

  printf("type in a letter: ");
  scanf("%c", &letter);

  letter = tolower(letter);

  switch (letter) {
    case 'a':
      printf("vowel\n");
      break; 
    case 'e':
      printf("vowel\n");
      break; 
    case 'i':
      printf("vowel\n");
      break; 
    case 'o':
      printf("vowel\n");
      break; 
    case 'u':
      printf("vowel\n");
      break; 
    default:
      printf("not a vowel\n");
      break;
  }

  return 0;
}