#include <stdio.h>

int getArrayIndex(int num)
{
  int q = num;
  int e = 1;
  while (q > 1)
  {
    q = (int)q / 2;
    e += 1;
  }
  return e;
}

int main(void)
{
  int num, r;

  printf("10진수 정수 입력: ");
  scanf("%d", &num);

  if (num > 1)
  {
    int index = getArrayIndex(num);

    int arr[index];
    int i = 0;
    r = num;
    while (r > 1)
    {
      arr[i] = r % 2;
      r = (int)r / 2;
      i++;
    }
    arr[i] = r;

    for (int j = i; j >= 0; j--)
    {
      printf("%d", arr[j]);
    }
  }
  else
  {
    printf("1");
  }

  return 0;
}