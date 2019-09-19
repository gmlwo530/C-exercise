#include <stdio.h>

int main(void)
{
  double rad;
  double area;
  printf("원의 반지름 입력 : ");
  scanf("%lf", &rad); // 실수 입력

  area = rad * rad * 3.14;
  printf("원의 넓이 : %f\n", area); // 실수 출력

  return 0;
}