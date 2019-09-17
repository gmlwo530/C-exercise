#include <stdio.h>

int main(void)
{
  int x = 0, y = 0, z = 0;

  z = x && y++; // x가 0이고 && 연산이므로 컴파일러가 x까지만 수행하고 y++는 읽지 않는다.
  printf("x: %d, y: %d, z: %d\n", x, y, z);

  x = 1;
  z = x && y++;
  printf("x: %d, y: %d, z: %d\n", x, y, z);
  return 0;
}