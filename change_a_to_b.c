#include <stdio.h>
#include <string.h>

int main(void)
{
  char ch;
  char s[20];
  int i = 0;

  while (1)
  {
    ch = getchar();

    if (ch == '\n')
      break;

    s[i] = ch;
    i++;
  }

  for(int j=0; j<strlen(s); j++){
    char tmp[3];
    if(s[j]=='a'){
      int tmpI = 0;
      for(int k=j; k<j+3;k++){
        tmp[tmpI++] = s[k];
      }

      if(!strncmp(tmp, "aaa", 3)){
       for(int k=j; k<j+3;k++){
        s[k] = 'b';
       } 
      }
    }
  }

  printf("----결과----\n");
  printf("%s", s);
  return 0;
}