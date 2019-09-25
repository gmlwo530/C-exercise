#include <stdio.h>

//문제 05-1의 2번
int main(void)
{
  double num1, num2;
  printf("두 수 입력 : ");
  scanf("%lf", &num1);
  scanf("%lf", &num2);

  printf("더하기 결과 : %f\n", num1 + num2);
  printf("곱하기 결과 : %f\n", num1 * num2);
  printf("빼기 결과 : %f\n", num1 - num2);
  printf("나누기 결과 : %f\n", num1 / num2);
  return 0;
}