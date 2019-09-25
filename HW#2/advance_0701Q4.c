#include <stdio.h>

//문제 07-1의 4번
int main(void)
{
  int num;
  int index = 1;
  printf("정수를 입력 해주세요 : ");
  scanf("%d", &num);

  if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
  {
    while (index < 10)
    {
      printf("%d x %d = %d\n", index, num, index * num);
      index++;
    }
  }
  else
  {
    printf("1부터 9까지의 자연수를 입력해주세요!");
  }

  return 0;
}