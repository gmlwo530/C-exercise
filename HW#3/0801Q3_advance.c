#include <stdio.h>

int main(void)
{
  int a, b, c;
  double average;

  printf("국어 점수 입력 : ");
  scanf("%d", &a);

  printf("영어 점수 입력 : ");
  scanf("%d", &b);

  printf("수학 점수 입력 : ");
  scanf("%d", &c);

  average = (double)(a + b + c) / 3;

  switch ((int)average / 10)
  {
  case 9:
    printf("A\n");
    break;

  case 8:
    printf("B\n");
    break;

  case 7:
    printf("C\n");
    break;

  case 6:
    printf("D\n");
    break;

  case 5:
    printf("D\n");
    break;

  default:
    printf("F\n");
    break;
  }

  return 0;
}