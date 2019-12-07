#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int main(void)
{
  int a, b;

  printf("비교하고 싶은 첫 번째 수 입력 : ");
  scanf("%d", &a);
  printf("비교하고 싶은 두 번째 수 입력 : ");
  scanf("%d", &b);

  printf("%d와 %d 중 큰 수는? : %d\n", a, b, MAX(a, b));
  return 0;
}