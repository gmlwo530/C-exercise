#include <stdio.h>

int main(void)
{
  int num;
  int result = 1;
  printf("정수 입력 : ");
  scanf("%d", &num);

  for (int i = 1; i < num + 1; i++)
  {
    result *= i;
  }

  printf("결과 값 : %d", result);
  return 0;
}