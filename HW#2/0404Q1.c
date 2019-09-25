#include <stdio.h>

// 문제 04-4의 문제 1
int main(void)
{
  int num;
  printf("정수를 입력해주세요 : ");
  scanf("%d", &num);

  int num2 = ~num;
  num2 = num2 + 1;
  printf("결과 : %d", num2);
  return 0;
}