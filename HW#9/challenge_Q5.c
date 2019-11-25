#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1 = fopen(argv[1], "rt");
  FILE *fp2 = fopen(argv[2], "rt");
  char c1, c2;
  while (1)
  {
    c1 = fgetc(fp1);
    c2 = fgetc(fp2);

    if (c1 != c2)
    {
      printf("두 파일은 일치하지 않습니다\n");
      break;
    }
    else if (c1 == EOF && c2 == EOF)
    {
      printf("두 파일은 완벽하게 일치합니다\n");
      break;
    }
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}