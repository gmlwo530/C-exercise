#include <stdio.h>

// 문제 05-1의 4번
int main(void)
{
  int num;

  printf("숫자를 입력해주세요 : ");

  scanf("%d", &num);

  printf("아스키 코드 : %c\n", num);

  return 0;
}