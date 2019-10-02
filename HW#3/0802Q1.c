#include <stdio.h>

int main(void)
{
  for (int i = 1; i < 10; i++)
  {
    if (i % 2 != 0)
    {
      continue;
    }
    else
    {
      for (int j = 1; j < 10; j++)
      {
        if (j > i)
        {
          break;
        }
        else
        {
          printf("%d x %d = %d\n", i, j, i * j);
        }
      }
    }
  }

  return 0;
}