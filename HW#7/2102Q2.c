#include <stdio.h>

int main(void)
{
  char str1[20];
  char str2[20];
  char str3[40];
  int i;

  printf("str1 입력 : ");
  fgets(str1, sizeof(str1), stdin);

  printf("str2 입력 : ");
  fgets(str2, sizeof(str2), stdin);

  for (i = 0; str1[i] != '\n'; i++)
  {
    str3[i] = str1[i];
  }

  for (int j = 0; str2[j] != '\n'; j++)
  {
    str3[i - 1 + j] = str2[j];
  }

  printf("%s", str3);

  return 0;
}