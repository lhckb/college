#include <stdio.h>

int main()
{
  int age;

  printf("type in the age: ");
  scanf("%i", &age);

  if (age >= 18 && age <= 67) {
    printf("able to donate\n");
  }
  else {
    printf("cannot donate\n");
  }

  return 0;
}