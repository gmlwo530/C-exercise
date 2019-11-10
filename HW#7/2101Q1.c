#include <stdio.h>

int main(void)
{
  int ch;

  ch = getchar();
  if ('a' <= ch && ch <= 'z')
  {
    ch -= 32;
    putchar(ch);
  }
  else if ('A' <= ch && ch <= 'Z')
  {
    ch += 32;
    putchar(ch);
  }
  else
  {
    printf("입력 오류!");
  }

  return 0;
}