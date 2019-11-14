#include <stdio.h>

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

int squareArea(Rectangle rectangle)
{
  return (rectangle.rightPoint.xpos - rectangle.leftPoint.xpos) * (rectangle.rightPoint.ypos - rectangle.leftPoint.ypos);
}

int main(void)
{
  Rectangle rectangle = {{10, 10}, {90, 90}};

  printf("사각형의 넓이 : %d", squareArea(rectangle));
  return 0;
}