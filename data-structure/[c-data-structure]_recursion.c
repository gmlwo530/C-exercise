// C언어로 쉽게 풀어 쓴 자료구조 2장 순환
#include <stdio.h>

double power(double x, int n)
{
  if (n == 0)
    return 1;
  else if ((n % 2) == 0)
    return power(x * x, n / 2);
  else
    return x * power(x * x, (n - 1) / 2);
}

void hanoi_tower(int n, char from, char tmp, char to)
{
  if (n == 1)
    printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
  else
  {
    hanoi_tower(n - 1, from, to, tmp);
    printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
    hanoi_tower(n - 1, tmp, from, to);
  }
}

int main(void)
{
  return 0;
}