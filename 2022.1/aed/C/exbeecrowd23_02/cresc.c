#include <stdio.h>
 
int main() {
 
    int x, y;

    do {
      scanf("%d", &x);
      scanf("%d", &y);

      if (x > y) {
        printf("decrescente\n");
      }
      else if (x < y) {
          printf("crescente\n");
      }
      // else {
      //   printf("\n");
      // }
    } while (x != y);
    
    return 0;
}