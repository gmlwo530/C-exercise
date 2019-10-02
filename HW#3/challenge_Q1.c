#include <stdio.h>

int main(void)
{
  int n;
  printf("10진수 정수 입력 : ");
  scanf("%d", &n);

  printf("10진수 : %d\n16진수 : %x\n", n, n);
  return 0;
}