#include <stdio.h>
#include <math.h>

struct point
{
  int x;
  int y;
};

void printCoordinate(struct point p)
{
  printf("X 좌표 %d, Y 좌표 %d\n", p.x, p.y);
}

double calDistance(struct point p1, struct point *p2)
{
  return sqrt((double)(p1.x - p2->x) * (p1.x - p2->x) + (double)(p1.y - p2->y) * (p1.y - p2->y));
}

int main(void)
{
  struct point p;
  printf("첫 번째 X 좌표 입력 : ");
  scanf("%d", &p.x);

  printf("첫 번째 Y 좌표 입력 : ");
  scanf("%d", &p.y);

  printCoordinate(p);

  struct point p2;

  struct point *pptr = &p2;

  printf("두 번째 X 좌표 입력 : ");
  scanf("%d", &p2.x);

  printf("두 번째 Y 좌표 입력 : ");
  scanf("%d", &p2.y);

  printf("두 점 사이의 거리는 %g", calDistance(p, pptr));

  return 0;
}