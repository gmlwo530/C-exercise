#include <stdio.h>

int max(int a, int b, int c)
{
  if (a >= b)
  {
    return a;
  }
  else
  {
    if (b >= c)
    {
      return b;
    }
    else
    {
      return c;
    }
  }
}
int min(int a, int b, int c)
{
  if (a < b)
  {
    return a;
  }
  else
  {
    if (b < c)
    {
      return b;
    }
    else
    {
      return c;
    }
  }
}

int main(void)
{
  printf("가장 큰 값 : %d\n", max(3, 4, 5));
  printf("가장 작은 값 : %d", min(37, 4, 12));
  return 0;
}
