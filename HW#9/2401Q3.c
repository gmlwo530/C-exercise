#include <stdio.h>

int main(void)
{
  FILE *fr = fopen("mystory.txt", "rt");
  char arr[100];

  while (fgets(arr, sizeof(arr), fr) != NULL)
  {
    puts(arr);
  }

  fclose(fr);
  return 0;
}