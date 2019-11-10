#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void makeComputerNum(int *cNum)
{
  *cNum = rand() % 10;

  while (1)
  {
    *(cNum + 1) = rand() % 10;
    if (*cNum != *(cNum + 1))
    {
      break;
    }
  }

  while (1)
  {
    *(cNum + 2) = rand() % 10;
    if (*cNum != *(cNum + 2) && *(cNum + 1) != *(cNum + 2))
    {
      break;
    }
  }
}

void startGame(int *cNum, int *num)
{
  static int i = 1;

  do
  {
    int strike = 0, ball = 0;
    printf("3개의 숫자 입력 : ");
    scanf("%d %d %d", num, num + 4, num + 8);

    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (num[j] == cNum[k])
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
  } while (*cNum != *num || *(cNum + 1) != *(num + 1) || *(cNum + 2) != *(num + 2));
}

int main(void)
{
  srand(time(NULL));

  int num[3];
  int cNum[3];

  makeComputerNum(cNum);

  printf("Game Start!\n");

  startGame(cNum, num);

  printf("Game Over!\n");

  return 0;
}