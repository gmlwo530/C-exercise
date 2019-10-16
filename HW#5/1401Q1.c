#include <stdio.h>

int SquareByValue(int num)
{
  return num * num;
}

void SquareByReference(int *num)
{
  (*num) *= (*num);
}

int main(void)
{
  int num = 10;
  int *p;
  p = &num;
  SquareByReference(p);
  printf("Square By Value - 5의 제곱 : %d\n", SquareByValue(5));
  printf("Square By Reference - 10의 제곱 : %d\n", num);
  return 0;
}