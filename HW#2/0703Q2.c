#include <stdio.h>

// 문제 07-3의 2번
int main(void)
{
  int sum = 0, num = 0;

  do
  {
    if (num % 2 == 0)
    {
      sum += num;
    }
    num++;
  } while (num <= 100);

  printf("결과 : %d", sum);

  return 0;
}