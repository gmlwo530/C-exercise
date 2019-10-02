#include <stdio.h>

void printGuGuDan(int start, int end)
{
  for (int i = start; i < end + 1; i++)
  {
    for (int j = 1; j < 10; j++)
    {
      printf("%d x %d = %d\n", i, j, i * j);
    }
  }
}

int main(void)
{
  int n1, n2;
  printf("정수 입력 : ");
  scanf("%d %d", &n1, &n2);

  n1 >= n2 ? printGuGuDan(n2, n1) : printGuGuDan(n1, n2);

  return 0;
}