#include <stdio.h>

void MaxAndMin(int **maxPtr, int **minPtr, int arr[5])
{
  int *max, *min;
  max = min = &arr[0];

  for (int i = 1; i < 5; i++)
  {
    if (arr[i] > *max)
    {
      max = &arr[i];
    }

    if (arr[i] < *min)
    {
      min = &arr[i];
    }
  }

  *maxPtr = max;
  *minPtr = min;
}

int main(void)
{
  int *maxPtr;
  int *minPtr;
  int arr[5] = {1, 2, 3, 4, 5};

  MaxAndMin(&maxPtr, &minPtr, arr);

  printf("최대값 : %d\n", *maxPtr);
  printf("최소값 : %d\n", *minPtr);
  return 0;
}