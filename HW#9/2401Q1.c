#include <stdio.h>

int main(void)
{
  FILE *fw = fopen("mystory.txt", "wt");
  char input[20];

  fputs("이름 : ", stdout);
  scanf("%s", input);
  fputs("#이름 : ", fw);
  fputs(input, fw);

  fputs("나이 : ", stdout);
  scanf("%s", input);
  fputs("\n#나이 : ", fw);
  fputs(input, fw);

  fputs("전화번호 : ", stdout);
  scanf("%s", input);
  fputs("\n#전화번호 : ", fw);
  fputs(input, fw);

  fclose(fw);

  return 0;
}