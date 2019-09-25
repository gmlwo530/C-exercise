#include <stdio.h>

//문제 07-1의 1번
int main(void)
{
  int num;
  int index = 0;

  printf("정수를 입력해주세요 : ");
  scanf("%d", &num);

  while (index < num)
  {
    printf("Hello World!\n");
    index++;
  }
  return 0;
}