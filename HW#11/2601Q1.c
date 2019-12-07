#include <stdio.h>
#define ADD(x, y, z) (x + y + z)
#define MUL(x, y, z) (x * y * z)

int main(void)
{
  printf("덧셈 : %d\n", ADD(2, 3, 4));
  printf("곱셈 : %d\n", MUL(2, 3, 4));
  return 0;
}