#include <stdio.h>

// 문제 07-3의 3번
int main(void)
{
  int num = 2;

  do
  {
    printf("\n");
    int num2 = 1;

    do
    {
      printf("%d x %d = %d | ", num, num2, num * num2);
      num2++;
    } while (num2 < 10);

    num++;
  } while (num < 10);
  return 0;
}