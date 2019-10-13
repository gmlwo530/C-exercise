#include <stdio.h>

int main(void)
{
  printf("현재 당신이 소유하고 있는 금액 : 3500\n");

  int cream = 500, shrimp = 700, coke = 400, totalMoney = 3500;

  for (int i = 1; i <= (int)(totalMoney / cream); i++)
  {
    int creamCount = 0, remainMoney = totalMoney;
    creamCount += i;
    remainMoney = totalMoney - (creamCount * cream);

    for (int j = 1; j <= (int)(remainMoney / shrimp); j++)
    {
      int shrimpCount = 0, cokeCount = 0, remainMoney2 = remainMoney;
      shrimpCount += j;
      remainMoney2 = remainMoney2 - (shrimpCount * shrimp);

      if (remainMoney2 % coke == 0)
      {
        printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", creamCount, shrimpCount, cokeCount += remainMoney2 / coke);
      }
    }
  }
  printf("어떻게 구입하시겠습니까?\n");
  return 0;
}