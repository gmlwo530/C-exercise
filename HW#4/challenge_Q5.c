#include <stdio.h>

int main(void)
{
  int num = 2, count = 0;

  while (count < 10)
  {
    int numIsPrime = 1;
    for (int i = 2 ; i < num ; i++){
      if (num % i == 0)   {
        numIsPrime = 0;
        break;
      }
    }

    if (numIsPrime){
      printf("%d ", num);
      count++; 
    }
    num++;
  }
  return 0;
}