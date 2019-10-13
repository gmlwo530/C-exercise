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

  int *ptr = arr;
  (*ptr) += 2;

  ptr++;

  (*ptr) += 2;

  ptr++;

  (*ptr) += 2;

  ptr++;

  (*ptr) += 2;

  ptr++;

  (*ptr) += 2;

  ptr++;

  for (int j = 0; j < 5; j++)
  {
    printf("%d ", arr[j]);
  }
  return 0;
}