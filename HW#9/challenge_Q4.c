#include <stdio.h>

int main(int argc, char * argv[])
{
  FILE *fp = fopen(argv[1], "rt");
  char word[30];
  int cA, cP, ch;
  ch=cA=cP=0;
  

  do{
    fscanf(fp, "%s", &word);
    if(word[0] == 'A' || word[0]=='a'){
      ++cA;
    }else if (word[0] == 'P' || word[0] == 'p'){
      ++cP;
    }
  }while((ch = fgetc(fp)) != EOF);

  printf("A로 시작하는 단어의 수 : %d\n", cA);
  printf("P로 시작하는 단어의 수 : %d\n", cP);
  fclose(fp);

  return 0;
}