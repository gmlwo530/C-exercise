#include <stdio.h>

int main(void)
{
  int num1, num2;
  int sum = 0;
  printf("첫 번째 정수 입력 : ");
  scanf("%d", &num1);

  printf("두 번째 정수 입력 : ");
  scanf("%d", &num2);

  for (int i = num1; i < num2 + 1; i++)
  {
    sum += i;
  }

  printf("결과 값 : %d", sum);
  return 0;
}