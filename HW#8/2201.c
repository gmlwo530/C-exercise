#include <stdio.h>

struct employee
{
  char name[20];
  char num[15];
  int pay;
};

int main(void)
{
  char name[20];
  char num[15];
  int pay;

  printf("이름 입력 : ");
  scanf("%s", name);

  printf("주민번호 입력 : ");
  scanf("%s", num);

  printf("급여 입력 : ");
  scanf("%d", &pay);

  struct employee myEmployee = {name, num, pay};

  printf("이름 : %s\n주민번호 : %s\n급여: %d", name, num, pay);
  return 0;
}