#include <stdio.h>

int mypow(int n)
{
  if (n == 0)
    return 1;
  return 2 * mypow(n - 1);
}

int main(void)
{
  int num;
  printf("정수 입력 : ");
  scanf("%d", &num);

  printf("2의 %d승은 %d", num, mypow(num));
  return 0;
}