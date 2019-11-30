#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReverse(char *s)
{ 
  for (int j = strlen(s) - 1; j >=0; j--){
    if (s[j] == ' ' || s[j] == '\n'){
      s[j] = '\0';
      printf("%s ", &(s[j]) + 1); 
    }
  }

  printf("%s ", s); 
}

int main(void)
{
  int size;
  char *s;

  printf("문자열 길이 입력 : ");
  scanf("%d", &size);

  while (getchar() != '\n')
    ;

  s = (char *)malloc(sizeof(char) * size);
  printf("문자 입력 : ");
  fgets(s, size, stdin);

  printReverse(s);

  free(s);
  return 0;
}