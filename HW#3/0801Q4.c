#include <stdio.h>

int main(void)
{
  int num1, num2;

  printf("첫 번째 정수 입력 : ");
  scanf("%d", &num1);

  printf("두 번째 정수 입력 : ");
  scanf("%d", &num2);

  printf("결과 : %d", num1 >= num2 ? num1 - num2 : num2 - num1);

  return 0;
}