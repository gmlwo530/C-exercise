#include <stdio.h>

// 문제 05-1의 1번
int main(void)
{
  int leftX, leftY, rightX, rightY;

  printf("좌 상단의 x, y 좌표 : ");
  scanf("%d %d", &leftX, &leftY);

  printf("우 상단의 x, y 좌표 : ");
  scanf("%d %d", &rightX, &rightY);

  printf("두 점이 이루는 직사각형의 넓이는 %d입니다", (rightX - leftX) * (rightY - leftY));

  return 0;
}