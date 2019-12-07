#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int main(void)
{
  printf("2와 5 중 큰 수는? : %d", MAX(2, 5));
  return 0;
}