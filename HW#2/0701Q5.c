#include <stdio.h>

// 문제 07-1의 5번
int main(void)
{
  int num;
  int num2;
  double sum = 0;
  int a = 0;
  printf("평균 낼 정수의 갯수를 입력 해주세요 : ");
  scanf("%d", &num);

  while (a < num)
  {
    printf("정수를 입력 해주세요 : ");
    scanf("%d", &num2);
    sum = sum + num2;
    a++;
  }

  printf("평균값 : %f", sum / num);
  return 0;
}