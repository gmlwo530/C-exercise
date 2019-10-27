#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i;
  printf("난수의 범위 : 0부터 99까지\n");
  
  srand(time(0));
  for(i=0; i<5;i++){
    printf("난수 출력: %d \n", rand() % 99);
  }
  return 0;
}