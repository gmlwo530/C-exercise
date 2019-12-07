#include <stdio.h>
#include <string.h>

#define BUF_SIZE 16

void printLine(int filePosition, char arr[])
{
  printf("%06X: ", filePosition);
  for (int i = 0; i < BUF_SIZE; i++)
  {
    printf("%02X ", arr[i]);
  }

  printf("|| ");

  for (int i = 0; i < BUF_SIZE; i++)
  {
    if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= '0' && arr[i] <= '9'))
    {
      printf("%c", arr[i]);
    }
    else
    {
      printf(".");
    }
  }
  printf(" ||\n");
}

void printLastLine(int filePosition, char arr[], int size)
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
      if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= '0' && arr[i] <= '9'))
      {
        printf("%c", arr[i]);
      }
      else
      {
        printf(".");
      }
    }
    else
    {
      printf(" ");
    }
  }
  printf(" ||\n");
}

int main(void)
{
  char arr[BUF_SIZE];
  FILE *fp;
  char path[20];
  printf("파일이름 명 : ");
  scanf("%s", path);
  fp = fopen(path, "rb");
  int ret;
  int filePosition;

  if (fp == NULL)
  {
    printf("파일 오픈 실패\n");
    return 0;
  }

  for (filePosition = 0;; filePosition += BUF_SIZE)
  {
    if ((ret = (int)fread(arr, 1, 16, fp)) != BUF_SIZE)
    {
      printLastLine(filePosition, arr, ret);
      break;
    }
    printLine(filePosition, arr);
  }
  fclose(fp);
  return 0;
}