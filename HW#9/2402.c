#include <stdio.h>

long FileSize(FILE *fp)
{
  long pos, size;

  pos = ftell(fp);

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  fseek(fp, pos, SEEK_SET);

  return size;
}

int main(void)
{
  char str[100];

  FILE *fp = fopen("data.txt", "rt");
  
  fgets(str,100,fp);

  printf("파일내용 : %s\n", str);
  printf("파일크기 : %ldByte\n", FileSize(fp));

  fclose(fp);

  return 0;
}