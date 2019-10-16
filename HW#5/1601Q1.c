#include <stdio.h>

void printArray(int arr[][9])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int arr[3][9];

  for (int i = 2; i < 5; i++)
  {
    for (int j = 1; j < 10; j++)
    {
      arr[i - 2][j - 1] = i * j;
    }
  }
  printArray(arr);
  return 0;
}