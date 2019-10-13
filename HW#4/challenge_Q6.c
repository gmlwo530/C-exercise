#include <stdio.h>

int main(void)
{
  int s;
  printf("초(second) 입력 :");
  scanf("%d", &s);

  int h = (int)s / 3600;
  int m = (s - (h * 3600)) / 60;
  s = s - (h * 3600) - (m * 60);

  printf("[h: %d, m: %d, s: %d]\n", h, m, s);
  return 0;
}