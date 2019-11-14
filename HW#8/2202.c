#include <stdio.h>

struct employee
{
  char name[20];
  char num[15];
  int pay;
};

int main(void)
{
  struct employee arr[3];

  for (int i = 0; i < 3; i++)
  {
    struct employee myEmployee;

    char name[20];
    char num[15];
    int pay;

    printf("이름 입력 : ");
    scanf("%s", myEmployee.name);

    printf("주민번호 입력 : ");
    scanf("%s", myEmployee.num);

    printf("급여 입력 : ");
    scanf("%d", &myEmployee.pay);

    arr[i] = myEmployee;
  }

  for (int i = 0; i < 3; i++)
  {
    printf("\n이름 : %s\n주민번호 : %s\n급여: %d", arr[i].name, arr[i].num, arr[i].pay);
  }

  return 0;
}