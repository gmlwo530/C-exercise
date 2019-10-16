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

void printName(int num)
{
  switch (num)
  {
  case 0:
    printf("철희 ");
    break;

  case 1:
    printf("철수 ");
    break;

  case 2:
    printf("영희 ");
    break;

  case 3:
    printf("영수 ");
    break;
  }
}

void printSubject(int num)
{
  switch (num)
  {
  case 0:
    printf("국어 : ");
    break;

  case 1:
    printf("영어 : ");
    break;

  case 2:
    printf("수학 : ");
    break;

  case 3:
    printf("국사 : ");
    break;
  }
}

int main(void)
{
  int arr[5][5];

  for (int i = 0; i < 4; i++)
  {
    printName(i);
    printf("점수 입력\n");

    for (int j = 0; j < 4; j++)
    {
      printSubject(j);
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