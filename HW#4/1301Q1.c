#include <stdio.h>

int main(void)
{
  int arr[5] = {
      1,
      2,
      3,
      4,
      5,
  };

  for (int i = 0; i < 5; i++)
  {
    int *ptr = &arr[i];
    (*ptr)++;
    (*ptr)++;
  }

  for (int j = 0; j < 5; j++)
  {
    printf("%d ", arr[j]);
  }
  return 0;
}