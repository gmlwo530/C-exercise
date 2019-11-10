#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));

  int i = 1;
  int num1, num2, num3;
  int cNum1, cNum2, cNum3;

  cNum1 = rand() % 10;

  while (1)
  {
    cNum2 = rand() % 10;
    if (cNum1 != cNum2)
    {
      break;
    }
  }

  while (1)
  {
    cNum3 = rand() % 10;
    if (cNum1 != cNum3 && cNum2 != cNum3)
    {
      break;
    }
  }

  int cArr[3] = {cNum1, cNum2, cNum3};

  printf("답 %d %d %d\n", cArr[0], cArr[1], cArr[2]);
  printf("Game Start!\n");

  do
  {
    int strike = 0, ball = 0;
    printf("3개의 숫자 입력 : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int arr[3] = {num1, num2, num3};

    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (arr[j] == cArr[k])
        {
          if (j == k)
          {
            strike++;
          }
          else
          {
            ball++;
          }
        }
      }
    }

    printf("%d 번쨰 도전 결과 : %dstrike %dball!!\n", i++, strike, ball);
  } while (num1 != cNum1 || num2 != cNum2 || num3 != cNum3);

  printf("Game Over!\n");

  return 0;
}