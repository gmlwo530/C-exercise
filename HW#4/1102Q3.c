#include <stdio.h>

int main(void)
{
  char str[100];
  printf("영단어 입력 : ");
  scanf("%s", str);
  int i = 1;
  int maxAscii = str[0];

  while (str[i] != 0)
  {
    if (maxAscii < str[i])
      maxAscii = str[i];
    i++;
  }

  printf("가장 큰 문자 %c", maxAscii);
  return 0;
}