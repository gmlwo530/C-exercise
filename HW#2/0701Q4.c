#include <stdio.h>

//문제 07-1의 4번
int main(void)
{
  int num;
  int index = 1;
  printf("정수를 입력 해주세요 : ");
  scanf("%d", &num);

  while (index < 10)
  {
    printf("%d x %d = %d\n", index, num, index * num);
    index++;
  }
  return 0;
}