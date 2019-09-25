#include <stdio.h>

// 문제 07-2의 문제 1
int main(void)
{
  int num = 0;
  int sum = 0;
  int a = 0;

  while (a < 5)
  {
    printf("1 이상의 정수를 입력 해주세요 : ");
    scanf("%d", &num);
    if (num >= 1)
    {
      sum = sum + num;
      a++;
    }
    else
    {
      while (1)
      {
        printf("1 이상의 정수를 다시 입력 해주세요 : ");
        scanf("%d", &num);

        if (num >= 1)
        {
          sum = sum + num;
          a++;
          break;
        }
      }
    }
  }

  printf("결과 : %d", sum);
  return 0;
}