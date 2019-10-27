#include <stdio.h>

int arrSize;

void makeArray(int arr[][arrSize])
{
  int maxColSize, maxRowSize, minColSize, minRowSize, currentCol, currentRow;
  maxColSize = maxRowSize = arrSize - 1;
  minRowSize = minColSize = currentRow = currentCol = 0;
  int n = 1;

  while (n <= (arrSize * arrSize))
  {
    while (currentCol <= maxColSize)
    {
      arr[currentRow][currentCol] = n;
      currentCol++;
      n++;
    }
    minRowSize++;
    currentCol--;
    currentRow++;

    while (currentRow <= maxRowSize)
    {
      arr[currentRow][currentCol] = n;
      currentRow++;
      n++;
    }
    maxColSize--;
    currentRow--;
    currentCol--;

    while (currentCol >= minColSize)
    {
      arr[currentRow][currentCol] = n;
      currentCol--;
      n++;
    }
    minColSize++;
    currentCol++;
    currentRow--;

    while (currentRow >= minRowSize)
    {
      arr[currentRow][currentCol] = n;
      currentRow--;
      n++;
    }
    maxRowSize--;
    currentRow++;
    currentCol++;
  }
}

void printArray(int arr[][arrSize])
{
  for (int i = 0; i < arrSize; i++)
  {
    for (int j = 0; j < arrSize; j++)
    {
      printf("%2d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int n;
  printf("숫자를 입력하시오 : ");
  scanf("%d", &n);

  arrSize = n;

  int arr[arrSize][arrSize];

  makeArray(arr);

  printArray(arr);

  return 0;
}