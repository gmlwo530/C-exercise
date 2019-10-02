#include <stdio.h>

void printFibonaci(int n)
{
  int n1 = 0, n2 = 1;

  printf("%d %d", n1, n2);

  for (int i = 0; i < n - 2; i++)
  {
    int temp = n1 + n2;
    n1 = n2;
    n2 = temp;
    printf(" %d", n2);
  }
}

int main(void)
{
  int n;
  printf("정수 입력 : ");
  scanf("%d", &n);

  printFibonaci(n);

  return 0;
}