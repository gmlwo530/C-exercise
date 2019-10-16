#include <stdio.h>

void printArray(int arr[][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int arr[5][5];

  for (int i = 0; i < 4; i++)
  {
    printf("점수 입력\n");

    for (int j = 0; j < 4; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int sum = 0;
    for (int j = 0; j < 4; j++)
    {
      sum += arr[i][j];
    }
    arr[i][4] = sum;
  }

  for (int j = 0; j < 4; j++)
  {
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
      sum += arr[i][j];
    }
    arr[4][j] = sum;
  }

  arr[4][4] = 0;

  printArray(arr);

  return 0;
}