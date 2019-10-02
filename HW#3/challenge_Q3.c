#include <stdio.h>

int main(void)
{
  int n1, n2, r;
  printf("정수 입력 : ");
  scanf("%d %d", &n1, &n2);

  while (n2 > 0)
  {
    r = n1 % n2;
    n1 = n2;
    n2 = r;
  }

  printf("최대 공약수 : %d\n", n1);

  return 0;
}