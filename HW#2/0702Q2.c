#include <stdio.h>

// 문제 07-2의 2번
int main(void)
{
  int num = 0;
  int index = 0;

  while (index < 5)
  {
    int index2 = 0;

    while (index2 < num)
    {
      printf("o ");
      index2++;
    }
    printf("*\n");
    num++;
    index++;
  }
  return 0;
}