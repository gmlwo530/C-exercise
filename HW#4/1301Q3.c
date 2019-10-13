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

  int *ptr = &arr[4];

  int sum = 0;

  sum += *ptr;
  ptr--;
  sum += *ptr;
  ptr--;
  sum += *ptr;
  ptr--;
  sum += *ptr;
  ptr--;
  sum += *ptr;

  printf("%d", sum);

  return 0;
}