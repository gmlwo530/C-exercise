#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));

  int result1 = rand() % 6;
  int result2 = rand() % 6;
  printf("주사위 1의 결과 %d \n", (result1 == 0) ? 6 : result1);
  printf("주사위 2의 결과 %d \n", (result2 == 0) ? 6 : result2);

  return 0;
}