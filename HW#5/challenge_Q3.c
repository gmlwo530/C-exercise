#include <stdio.h>

int main(void)
{
  int arr[10];
  int s = 0, e = 9;

  printf("총 10개의 숫자 입력\n");
  for (int i = 0; i < 10; i++)
  {
    int num;
    printf("입력: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
      arr[e] = num;
      e--;
    }
    else
    {
      arr[s] = num;
      s++;
    }
  }

  printf("배열 요소의 출력 : ");

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}