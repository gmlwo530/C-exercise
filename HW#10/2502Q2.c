#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *arr;
  int num = 0;

  int size = 5;
  int count = 0;

  arr = (int *)malloc(sizeof(int) * size);

  while (1)
  {
    printf("정수 입력 : ");
    scanf("%d", &num);

    if (num == -1)
      break;

    if (count == size)
    {
      arr = (int *)realloc(arr, sizeof(int) * (size + 3));
      arr[count] = num;
    }
    else
    {
      arr[count] = num;
    }

    count++;
  }

  for (int i = 0; i < count; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}