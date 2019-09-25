#include <stdio.h>

// 문제 04-4의 문제 2
int main(void)
{
  int num = 3;

  num = num << 3;
  num = num >> 2;

  printf("결과 : %d", num);
  return 0;
}