#include <stdio.h>

int main(void)
{
  FILE *fw = fopen("mystory.txt", "at");
  char input[20];

  fputs("좋아하는 음식 : ", stdout);
  scanf("%s", input);
  fputs("\n#좋아하는 음식 : ", fw);
  fputs(input, fw);

  fputs("취미 : ", stdout);
  scanf("%s", input);
  fputs("\n#취미 : ", fw);
  fputs(input, fw);

  fclose(fw);
  return 0;
}