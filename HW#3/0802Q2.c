#include <stdio.h>

int main(void)
{
  for (int a = 0; a < 10; a++)
  {
    for (int z = 0; z < 10; z++)
    {
      if (a + z == 9)
      {
        printf("A : %d, Z : %d\n", a, z);
      }
      else
      {
        continue;
      }
    }
  }
  return 0;
}