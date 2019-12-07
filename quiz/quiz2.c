#include <stdio.h>
#include <string.h>

#define BUF_SIZE 16

void printLastLine(char arr[], int filePosition, int size)
{
  printf("%06X: ", filePosition);
  for (int i = 0; i < BUF_SIZE; i++)
  {
    if (i < size)
    {
      printf("%02X ", arr[i]);
    }
    else
    {
      printf("   ");
    }
  }

  printf("|| ");

  for (int i = 0; i < BUF_SIZE; i++)
  {
    if (i < size)
    {
      if (arr[i] != 0 && arr[i] != 7 && arr[i] != 8 && arr[i] != 9 && arr[i] != 10 && arr[i] != 12 && arr[i] != 13 && arr[i] != 27 && arr[i] != 127)
      {
        printf("%c", arr[i]);
      }
      else if (arr[i] == 13)
      {
        putchar(0x1B);
      }
      else if (arr[i] == 10)
      {
        putchar(0x1A);
      }
      else
      {
        printf(" ");
      }
    }
    else
    {
      printf(" ");
    }
  }

  printf(" ||\n");
}

void printLine(char arr[], int filePosition)
{
  printf("%06X: ", filePosition);
  for (int i = 0; i < BUF_SIZE; i++)
  {
    printf("%02X ", arr[i]);
  }

  printf("|| ");

  for (int i = 0; i < BUF_SIZE; i++)
  {
    if (arr[i] != 0 && arr[i] != 7 && arr[i] != 8 && arr[i] != 9 && arr[i] != 10 && arr[i] != 12 && arr[i] != 13 && arr[i] != 27 && arr[i] != 127)
    {
      printf("%c", arr[i]);
    }
    else if (arr[i] == 13)
    {
      putchar(0x1B);
    }
    else if (arr[i] == 10)
    {
      putchar(0x1A);
    }
    else
    {
      printf(" ");
    }
  }

  printf(" ||\n");
}

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    printf("에러 : 2개의 인수를 입력 해야합니다\n");
    return 0;
  }

  
  char arr[BUF_SIZE];
  FILE *fp;
  int filePosition;

  int n = 3;

  if ((fp = fopen("in2.txt", "rb")) == NULL)
  {
    printf("파일을 열 수 없습니다\n");
    return 0;
  }

  for (filePosition = 0;; filePosition += BUF_SIZE)
  {
    if (n == 0)
    {
      char input[20];
      printf("Type ENTER to continue:");

      if (getchar() != '\n')
      {
        return 0;
      }
    }

    int size = (int)fread(arr, 1, BUF_SIZE, fp);
    if (size != BUF_SIZE)
    {
      printLastLine(arr, filePosition, size);
      break;
    }
    printLine(arr, filePosition);
    n--;
  }

  return 0;
}