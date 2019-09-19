#include <stdio.h>

// 문제 03-1의 문제 2
int main(void)
{
  int num1, num2, num3;
  printf("첫 번째 정수를 입력 해주세요 : ");
  scanf("%d", &num1);

  printf("두 번째 정수를 입력 해주세요 : ");
  scanf("%d", &num2);

  printf("세 번째 정수를 입력 해주세요 : ");
  scanf("%d", &num3);

  printf("%dx%d+%d=%d", num1, num2, num3, num1*num2+num3);

  return 0;
}