#include <stdio.h>

int main(void)
{
  char str[100];
  printf("영단어 입력 : ");
  scanf("%s", str);

  int wordLen = 0;

  do
  {
    wordLen++;
  } while (str[wordLen] != 0);

  for (int i = 0; i < (int) (wordLen / 2); i++)
  {
    char temp;

    temp = str[i];
    str[i] = str[wordLen - 1 - i];
    str[wordLen - 1 -i] = temp;
  }

  printf("역순 영단어 : %s\n", str);

  return 0;
}