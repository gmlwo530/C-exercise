#include <stdio.h>

// 문제 07-1의 문제 3
int main(void)
{
  int num;
  int sum = 0;

  while (1)
  {
    printf("정수를 입력 해주세요 : ");
    scanf("%d", &num);
    if (num == 0)
      break;

    sum = sum + num;
  }

  printf("결과 : %d", sum);
  return 0;
}