#include <stdio.h>

int main(void)
{
  char arr[] = {'G', 'o', 'o', 'd', ' ', 't', 'i', 'm', 'e'};

  int arrLen = sizeof(arr) / sizeof(char);

  for (int i = 0; i < arrLen; i++)
  {
    printf("%c", arr[i]);
  }
  return 0;
}