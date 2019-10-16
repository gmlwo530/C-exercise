#include <stdio.h>

void printArray(int arr[][2])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int arrA[][4] = {1, 2, 3, 4, 5, 6, 7, 8};

  int arrB[4][2];

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      arrB[j][i] = arrA[i][j];
    }
  }

  printArray(arrB);
  return 0;
}