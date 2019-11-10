#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));

  int win = 0;
  int draw = 0;

  int com, user;

  while (1)
  {
    printf("바위는 1 가위는 2 보는 3 : ");
    scanf("%d", &user);

    com = rand() % 3;

    if (com == 0)
      com += 3;

    switch (user)
    {
    case 1:
      switch (com)
      {
      case 1:
        printf("당신은 바위 선택, 컴퓨터는 바위 선택. 비겼습니다\n");
        draw++;
        break;
      case 2:
        printf("당신은 바위 선택, 컴퓨터는 가위 선택. 이겼습니다\n");
        win++;
        break;
      case 3:
        printf("당신은 바위 선택, 컴퓨터는 보 선택. 졌습니다\n");
        printf("승 %d, 무승부 %d", win, draw);
        return 0;
      }
      break;
    case 2:
      switch (com)
      {
      case 1:
        printf("당신은 가위 선택, 컴퓨터는 바위 선택. 졌습니다\n");
        printf("승 %d, 무승부 %d", win, draw);
        return 0;
      case 2:
        printf("당신은 가위 선택, 컴퓨터는 가위 선택. 비겼습니다\n");
        draw++;
        break;
      case 3:
        printf("당신은 가위 선택, 컴퓨터는 보 선택. 이겼습니다\n");
        win++;
        break;
      }
      break;
    case 3:
      switch (com)
      {
      case 1:
        printf("당신은 보 선택, 컴퓨터는 바위 선택. 이겼습니다\n");
        win++;
        return 0;
      case 2:
        printf("당신은 보 선택, 컴퓨터는 가위 선택. 졌습니다\n");
        printf("승 %d, 무승부 %d", win, draw);
        return 0;
      case 3:
        printf("당신은 보 선택, 컴퓨터는 보 선택. 비겼습니다\n");
        draw++;
        break;
      }
      break;
    }
  }

  return 0;
}