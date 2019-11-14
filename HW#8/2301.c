#include <stdio.h>

typedef struct point
{
  int xpos;
  int ypos;
} Point;

void SwapPoint(Point *pos1, Point *pos2)
{
  int temp;

  temp = pos1->xpos;
  pos1->xpos = pos2->xpos;
  pos2->xpos = temp;

  temp = pos1->ypos;
  pos1->ypos = pos2->ypos;
  pos2->ypos = temp;
}

int main(void)
{
  Point pos1 = {2, 4};
  Point pos2 = {5, 7};

  SwapPoint(&pos1, &pos2);

  printf("pos1 x : %d, y %d\n", pos1.xpos, pos1.ypos);
  printf("pos2 x : %d, y %d", pos2.xpos, pos2.ypos);
  return 0;
}