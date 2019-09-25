#include <stdio.h>

// 문제 07-1의 2
int main(void)
{
  int num;

  int index = 1;

  printf("양의 정수를 입력해주세요 : ");
  scanf("%d", &num);

  while (index < num + 1)
  {
    printf("%d ", 3 * index);
    index++;
  }
  return 0;
}