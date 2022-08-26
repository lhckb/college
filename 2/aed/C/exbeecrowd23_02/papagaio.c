#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
  char perna[9];

  while (scanf("%[^\n]", perna) != EOF) {
    switch (perna[0]){
      case 'e':
        printf("ingles\n");
        break;
      case 'd':
        printf("frances\n");
        break;
      case 'n':
        printf("portugues\n");
        break;
      default: 
        printf("caiu\n");
        break;
    }
  } 


  return 0;
}