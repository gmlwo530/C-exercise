#include <stdio.h>

int main(void)
{
  char buf[81];
  int cnt;

  for (cnt = 1; scanf("%80s", buf) != EOF; cnt++)
  {
    printf("Word %03d: %s\n", cnt, buf);
  }

  return 0;
}