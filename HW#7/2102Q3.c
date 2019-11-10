#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[20];
  char str2[20];

  char name1[20];
  char name2[20];
  char age1[3];
  char age2[3];

  int i, j, k, l;

  fgets(str1, sizeof(str1), stdin);
  fgets(str2, sizeof(str2), stdin);

  for (i = 0; str1[i] != 32; i++)
  {
    name1[i] = str1[i];
  }

  for (j = 0; str2[j] != 32; j++)
  {
    name2[j] = str2[j];
  }

  for (k = 0; str1[i + 1 + k] != '\n'; k++)
  {
    age1[k] = str1[i + 1 + k];
  }

  for (l = 0; str2[j + 1 + l] != '\n'; l++)
  {
    age2[l] = str2[j + 1 + l];
  }

  if (!strncmp(name1, name2, i > j ? j : i))
  {
    printf("이름이 같습니다\n");
  }
  else
  {
    printf("이름이 다릅니다\n");
  }

  if (!strncmp(age1, age2, k > l ? k : l))
  {
    printf("나이가 같습니다\n");
  }
  else
  {
    printf("나이가 다릅니다\n");
  }

  return 0;
}