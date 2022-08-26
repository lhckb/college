#include <stdio.h>

int main()
{
  char gender;
  int age;

  printf("enter the gender ('f' or 'm'): ");
  scanf("%c", &gender);

  printf("type in the age: ");
  scanf("%i", &age);

  if (gender == 'f' && age < 25) {
    printf("ACEITA\n");
  }
  else {
    printf("NÃO ACEITA\n");
  }

  return 0;
}