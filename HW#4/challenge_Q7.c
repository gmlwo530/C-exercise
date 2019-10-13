#include <stdio.h>

int main(void)
{
  int k = 0, n;
  int result = 1;
  printf("실수 n 입력 :");
  scanf("%d", &n);

  do
  {
    result *= 2;
    k++;
  } while (result <= n);

  printf("공식을 만족하는 k의 최댓값은 %d", k - 1);
  return 0;
}