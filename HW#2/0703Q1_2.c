#include <stdio.h>

// 문제 07-3의 1번(방법 2)
int main(void)
{
  int total = 0, num = 0;

  printf("정수 입력(0 to quit): ");
  scanf("%d", &num);

  total = total + num;

  while (num != 0)
  {
    printf("정수 입력(0 to quit): ");
    scanf("%d", &num);
    total = total + num;
  }
  printf("합계: %d \n", total);

  return 0;
}