#include <stdio.h>

// 문제 05-1의 5번
int main(void)
{
  char alphabet;

  printf("문자를 입력해주세요 : ");

  scanf("%c", &alphabet);

  printf("아스키 코드에 대응 되는 숫자: %d\n", alphabet);

  return 0;
}