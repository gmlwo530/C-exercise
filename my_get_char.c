#include <stdio.h>

int main(void)
{
  int ch;
  while (1)
  {
    ch = getchar();

    if (ch == '\0')
      break;

    if ('a' <= ch && ch <= 'z')
    {
      ch -= 32;
    }
    else if ('A' <= ch && ch <= 'Z')
    {
      ch += 32;
    }

    putchar(ch);
  }
  return 0;
}