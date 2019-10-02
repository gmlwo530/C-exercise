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

  if (average >= 90)
  {
    printf("A");
  }
  else if (average >= 80)
  {
    printf("B");
  }
  else if (average >= 70)
  {
    printf("C");
  }
  else if (average >= 50)
  {
    printf("D");
  }
  else
  {
    printf("F");
  }

  return 0;
}