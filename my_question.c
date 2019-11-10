#include <stdio.h>

void printArray(int (*arr)[15], int row)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < row; j++)
    {
      if (arr[i][j] == -1)
      {
        printf("-- ");
      }
      else if (arr[i][j] == -2)
      {
        printf("| ");
      }
      else if (arr[i][j] == -3)
      {
        printf("+ ");
      }
      else
      {
        printf("%2d ", arr[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main(void)
{
  int arr[7][7];
  int num;

  printf("4부터 7까지 숫자 하나 입력 : ");
  scanf("%d", &num);

  printArray(arr, num);

  return 0;
}