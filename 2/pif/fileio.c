#include <stdio.h>

int main()
{
  FILE* file = fopen("teste.txt", "w");

  fprintf(file, "patrick very hot sex white boy sex");
  fclose(file);

  

  return 0;
}