#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *out;

  out = (char *)calloc(6, sizeof(char));

  strcpy(out, "abc");
  strcat(out, "dfe");

  printf("%s\n", out);

  return 0;
}