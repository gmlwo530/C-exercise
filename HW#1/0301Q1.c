#include <stdio.h>

// 문제 03-1의 문제 1
int main(void)
{
  int num1, num2;
  printf("첫 번째 정수를 입력 해주세요 : ");
  scanf("%d", &num1);

  printf("두 번째 정수를 입력 해주세요 : ");
  scanf("%d", &num2);

  printf("두 정수의 뺄셈 결과 : %d\n", num1 - num2);
  printf("두 정수의 곱셈 결과 : %d\n", num1 * num2);
  
  return 0;
}