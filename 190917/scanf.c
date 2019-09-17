#include <stdio.h>

int main(void)
{
  int num;
  scanf("%d", &num); // &을 붙인 이유는 num의 주소를 입력하기 위함이다 (call-by-reference)
  return 0;
}