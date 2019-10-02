#include <stdio.h>

int main(void)
{
  int n = 24;

  switch (n / 10)
  {
  case 0:
    printf("10미만");
    break;
  case 1:
    printf("10이상 20미만");
    break;
  case 2:
    printf("20이상 30미만");
    break;
  default:
    printf("30이상");
    break;
  }
  return 0;
}