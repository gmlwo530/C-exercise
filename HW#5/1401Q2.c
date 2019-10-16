#include <stdio.h>

void Swap(int *num1, int *num2, int *num3)
{
  int temp = *num1;
  *num1 = *num2;
  *num2 = *num3;
  *num3 = temp;
}

int main(void)
{

  int num1 = 5, num2 = 6, num3 = 7;

  printf("바뀌기 전 num1 : %d, num2 : %d, num3 : %d\n", num1, num2, num3);

  Swap(&num1, &num2, &num3);

  printf("바뀌기 후 num1 : %d, num2 : %d, num3 : %d\n", num1, num2, num3);

  return 0;
}