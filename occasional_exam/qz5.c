#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN_TO_LIN 0
#define WIN_TO_MAC 1
#define LIN_TO_WIN 2
#define LIN_TO_MAC 3
#define MAC_TO_WIN 4
#define MAC_TO_LIN 5
#define NO 6

/*
window : CR + LF , linux : LF, mac os : LF, classic mac : CR
*/
#define CR '\r' // 0D
#define LF '\n' // 0A

void printLastLine(char arr[], int filePosition, int size)
{
  printf("%06X: ", filePosition);
  for (int i = 0; i < 16; i++)
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

  printf(" ||\n");
}

void printLine(char arr[], int filePosition)
{
  printf("%06X: ", filePosition);
  for (int i = 0; i < 16; i++)
  {
    printf("%02X ", arr[i]);
  }
  printf(" ||\n");
}

void printByHexCode(char *fileName)
{
  FILE *fp;
  int filePosition;
  char arr[16];

  if ((fp = fopen(fileName, "rb")) == NULL)
  {
    printf("파일을 열 수 없습니다\n");
  }

  for (filePosition = 0;; filePosition += 16)
  {
    int size = (int)fread(arr, 1, 16, fp);
    if (size != 16)
    {
      printLastLine(arr, filePosition, size);
      break;
    }
    printLine(arr, filePosition);
  }
}

int readOneByte(FILE *fp, char *byte)
{
  if (fread(byte, 1, 1, fp) < 1)
    return -1;
  return 0;
}

int putBytes(FILE *fp, char *bytes, int count)
{
  if (fwrite(bytes, 1, count, fp) != count)
    return -1;
  return 0;
}

int decideMode(char *fileName)
{
  FILE *fp;

  char oneChar;

  if ((fp = fopen(fileName, "rb")) == NULL)
  {
    printf("파일을 열 수 없습니다\n");
    return NO;
  }

  while (readOneByte(fp, &oneChar) == 0)
  {
    if (oneChar == CR)
    {
      char nextChar;
      readOneByte(fp, &nextChar);
      if (nextChar == LF)
      {
        printf("THIS FILE IS WIN\n");
        return WIN_TO_LIN;
        break;
      }
      else
      {
        printf("THIS FILE IS MAC\n");
        break;
      }
    }
    else if (oneChar == LF)
    {
      printf("THIS FILE IS LIN\n");
      return LIN_TO_WIN;
    }
  }

  return -1;
}

void swap(char *a, char *b)
{
  char tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(char *s)
{
  for (int i = 0; i < strlen(s) / 2; i++)
  {
    swap(&s[i], &s[strlen(s) - 1 - i]);
  }
}

int findIndexInString(char *s, char c)
{
  for (int i = 0; s[i]; i++)
  {
    if (s[i] == c)
    {
      return i;
    }
  }

  return -1;
}

char *extractFileName(char *path)
{
  char *tmp;
  int index;

  tmp = (char *)calloc(strlen(path) + 1, sizeof(char));
  strcpy(tmp, path);
  reverse(tmp);
  if ((index = findIndexInString(tmp, '\\')) >= 0)
  {
    tmp[index] = 0;
  }
  reverse(tmp);
  return tmp;
}

char *outFileName(char *path, int mode)
{
  char *tmp, *out, *modeString;

  int index;

  if (mode == LIN_TO_MAC || mode == WIN_TO_MAC)
  {
    modeString = "_mac";
  }
  else if (mode == MAC_TO_LIN || mode == WIN_TO_LIN)
  {
    modeString = "_lin";
  }
  else if (mode == MAC_TO_WIN || mode == LIN_TO_WIN)
  {
    modeString = "_win";
  }

  tmp = extractFileName(path);
  out = (char *)calloc(strlen(tmp) + 4, sizeof(char));
  if ((index = findIndexInString(tmp, '.')) < 0)
  {
    strcpy(out, tmp);
    strcat(out, modeString);
  }
  else
  {
    strncpy(out, tmp, index);
    strcat(out, modeString);
    strcat(out, &tmp[index]);
  }
  free((void *)tmp);

  return out;
}

int main(int argc, char *argv[])
{
  int mode, size;
  FILE *fpin, *fpout;
  char *out;

  char oneChar;

  char outBuf[2];

  if (argc < 2)
  {
    printf("입력 파일명 인자가 없습니다!\n");
    return -1;
  }

  printf("변경 전 : \n");
  printByHexCode(argv[1]);

  if ((mode = decideMode(argv[1])) == NO)
  {
    printf("변경 할 수 없습니다\n");
    return -1;
  }

  out = outFileName(argv[1], mode);

  if ((fpin = fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", argv[1]);
    return -1;
  }
  if ((fpout = fopen(out, "wb")) == NULL)
  {
    fprintf(stderr, "출력파일 %s를 열 수 없습니다.\n", out);
    return -1;
  }
  if (mode == LIN_TO_WIN)
    while (readOneByte(fpin, &oneChar) != -1)
    {
      if (oneChar == LF)
      {
        outBuf[0] = CR, outBuf[1] = LF;
        size = 2;
      }
      else
      {
        outBuf[0] = oneChar;
        size = 1;
      }

      if (putBytes(fpout, outBuf, size) == -1)
      {
        fprintf(stderr, "%s 파일 출력 오류\n", out);
        break;
      }
    }
  else
  {
    while (readOneByte(fpin, &oneChar) != -1)
    {
      if (oneChar == CR)
      {
        size = 0;
      }
      else
      {
        outBuf[0] = oneChar;
        size = 1;
      }
      if (size > 0)
        if (putBytes(fpout, outBuf, size) == -1)
        {
          fprintf(stderr, "%s 파일 출력 오류\n", out);
          break;
        }
    }
  }

  fclose(fpin);
  fclose(fpout);

  printf("\n\n변경 후 : \n");
  printByHexCode(out);
  return 0;
}