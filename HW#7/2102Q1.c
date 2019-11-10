#include <stdio.h>

int main(void)
{
  int ch;
  int sum = 0;
  while (1)
  {
    ch = getchar();

    if (ch == '\n')
      break;

    if ('0' <= ch && ch <= '9')
    {
      sum += (ch - '0');
    }
  }
  printf("결과 %d", sum);
  return 0;
}