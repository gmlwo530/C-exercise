#include <stdio.h>

int main(void)
{
  int arr[5];
  int max, min, sum;

  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &arr[i]);
  }

  max = arr[0];
  min = arr[0];
  sum = arr[0];

  for (int j = 1; j < 5; j++)
  {
    if (arr[j] > max)
      max = arr[j];
    if (arr[j] < min)
      min = arr[j];
    sum += arr[j];
  }

  printf("입력 된 정수 중에서 최댓값 : %d\n", max);
  printf("입력 된 정수 중에서 최솟값 : %d\n", min);
  printf("입력 된 정수의 총 합 : %d\n", sum);

  return 0;
}