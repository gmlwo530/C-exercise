#include <stdio.h>

void printArray(int arr[][4])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%2d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void rotateSmallArr(int arr[][4], int pRow, int pCol){
  int tmp;

  tmp = arr[pRow][pCol];
  arr[pRow][pCol] = arr[pRow+1][pCol];
  arr[pRow+1][pCol] = arr[pRow+1][pCol+1];
  arr[pRow+1][pCol+1] = arr[pRow][pCol+1];
  arr[pRow][pCol+1] = tmp;
}

void rotateArr(int arr[][4])
{
  int pRow, pCol;
  pRow=pCol=0;

  rotateSmallArr(arr, pRow, pCol);

  pRow+=2;

  rotateSmallArr(arr, pRow, pCol);

  pRow-=2;
  pCol+=2;
  
  rotateSmallArr(arr, pRow, pCol);
  
  pRow+=2;

  rotateSmallArr(arr, pRow, pCol);

  pRow=pCol=0;

  int t1, t2, t3, t4;
  t1 = arr[pRow][pCol];
  t2 = arr[pRow][pCol+1];
  t3 = arr[pRow+1][pCol];
  t4 = arr[pRow+1][pCol+1];

  arr[pRow][pCol] = arr[pRow+2][pCol];
  arr[pRow][pCol+1] = arr[pRow+2][pCol+1];
  arr[pRow+1][pCol] = arr[pRow+3][pCol];
  arr[pRow+1][pCol+1] = arr[pRow+3][pCol+3];

  pRow+=2;

  arr[pRow][pCol] = arr[pRow][pCol+2];
  arr[pRow][pCol+1] = arr[pRow][pCol+3];
  arr[pRow+1][pCol] = arr[pRow+1][pCol+2];
  arr[pRow+1][pCol+1] = arr[pRow+1][pCol+3];

  pCol+=2;

  arr[pRow][pCol] = arr[pRow - 2][pCol];
  arr[pRow][pCol+1] = arr[pRow - 2][pCol+1];
  arr[pRow+1][pCol] = arr[pRow-1][pCol];
  arr[pRow+1][pCol+1] = arr[pRow-1][pCol+1];

  pRow-=2;
  arr[pRow][pCol] = t1;
  arr[pRow][pCol+1] = t2;
  arr[pRow+1][pCol] = t3;
  arr[pRow+1][pCol+1] = t4;
}

int main(void)
{
  int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  printArray(arr);

  rotateArr(arr);

  printArray(arr);

  rotateArr(arr);

  printArray(arr);

  rotateArr(arr);

  printArray(arr);
  return 0;
}