#include <stdio.h>

int main(void)
{
  float num1 = 5.789f;
  float num2 = 3.24F + 2.33F; // it is same with 'f'

  float num3 = 3.24f + 5.12f;
  float num4 = 3.24f + 5.12;

  printf("sizeof(3.23f + 5.12f) = %d\n", sizeof(3.24f + 5.12f));
  printf("sizeof(3.23f + 5.12) = %d\n", sizeof(3.24f + 5.12));
  printf("num3 : %f\nnum4 : %f\n", num3, num4);

  return 0;
}