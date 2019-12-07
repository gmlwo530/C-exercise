#include <stdio.h>

#define PI 3.14
#define AREA(r) (r * r * PI)

int main(void)
{
  double radian;
  printf("원의 반지름 :");
  scanf("%lf", &radian);

  printf("원의 넓이 : %g\n", AREA(radian));
  return 0;
}