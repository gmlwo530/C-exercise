#include <stdio.h>

int main(void)
{
  char word[100];
  int wordLen = 0;

  printf("문자열 입력 : ");
  scanf("%s", word);

  for (int i = 0; word[i] != 0; i++)
    wordLen++;

  for (int i = 0; i < (int)wordLen / 2; i++)
  {
    if (word[i] != word[wordLen - 1 - i])
    {
      printf("회문이 아닙니다.\n");
      return 0;
    }
  }

  printf("회문 입니다.\n");
  return 0;
}