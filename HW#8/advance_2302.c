#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int xpos;
  int ypos;
} Point;

typedef struct rectangle
{
  Point leftPoint;
  Point rightPoint;
} Rectangle;

int error(Rectangle rectangle)
{
  return (rectangle.leftPoint.xpos >= 0 && rectangle.leftPoint.xpos <= 100) &&
         (rectangle.leftPoint.ypos >= 0 && rectangle.leftPoint.ypos <= 100) &&
         (rectangle.rightPoint.xpos >= 0 && rectangle.rightPoint.xpos <= 100) &&
         (rectangle.rightPoint.ypos >= 0 && rectangle.rightPoint.ypos <= 100);
}

int squareArea(Rectangle rectangle)
{
  return abs(rectangle.rightPoint.xpos - rectangle.leftPoint.xpos) * abs(rectangle.rightPoint.ypos - rectangle.leftPoint.ypos);
}

int main(void)
{
  Rectangle rectangle;

  printf("첫 번째 좌표의 x 좌표 입력 : ");
  scanf("%d", &rectangle.leftPoint.xpos);

  printf("첫 번째 좌표의 y 좌표 입력 : ");
  scanf("%d", &rectangle.leftPoint.ypos);

  printf("첫 번째 좌표의 x 좌표 입력 : ");
  scanf("%d", &rectangle.rightPoint.xpos);

  printf("첫 번째 좌표의 y 좌표 입력 : ");
  scanf("%d", &rectangle.rightPoint.ypos);

  if (!error(rectangle))
  {
    printf("입력 오류");
  }
  else
  {
    printf("사각형의 넓이 : %d", squareArea(rectangle));
  }
  return 0;
}