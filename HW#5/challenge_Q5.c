#include <stdio.h>

void BubbleSort(int arr[], int len)
{
  int i, j;

  int temp;

  for (i = 0; i < len - 1; i++)
  {
    for (j = 0; j < (len - i) - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  return;
}

int main(void)
{
  int i;

  int arr[7] = {0};

  int arrSize = sizeof(arr) / sizeof(int);

  for (i = 0; i < arrSize; i++)
  {
    printf("입력: ");
    scanf("%d", &arr[i]);
  }

  BubbleSort(arr, arrSize);

  for (i = 0; i < arrSize; i++)
    printf("%d ", arr[i]);

  printf("\n");

  return 0;
}
