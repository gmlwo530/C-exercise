#include <stdio.h>

int main(void)
{
  char str[100];
  printf("영단어 입력 : ");
  scanf("%s", str);
  int end = 0;

  while (str[end] != 0)
  {
    end++;
  }

  printf("영단어 길이 : %d", end);
  return 0;
}