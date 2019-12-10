#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN 'W'
#define LIN 'L'
#define MAC 'A'
#define NO_OS ' '

#define WIN_TO_LIN 0
#define WIN_TO_MAC 1
#define LIN_TO_WIN 2
#define LIN_TO_MAC 3
#define MAC_TO_WIN 4
#define MAC_TO_LIN 5
#define NO 6

/*
window : CR + LF , linux : LF, classic mac : CR
*/
#define CR '\r' // 0D
#define LF '\n' // 0A

char *programName;

void printUsageMessage()
{
  fprintf(stderr, "Usage: %s -W|L|A input_file output_file\n", programName);
}

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

int decideMode(char *fileName, char indicator)
{
  FILE *fp;

  char oneChar;

  char inputFileOS = NO_OS;

  int isExistSpecificChar = 0;

  if (indicator != WIN && indicator != LIN && indicator != MAC)
  {
    return NO;
  }

  if ((fp = fopen(fileName, "rb")) == NULL)
  {
    printf("파일을 열 수 없습니다\n");
    return NO;
  }

  while (readOneByte(fp, &oneChar) == 0)
  {
    if (oneChar == CR)
    {
      ++isExistSpecificChar;
      char nextChar;
      readOneByte(fp, &nextChar);
      if (nextChar == LF)
      {
        inputFileOS = WIN;
      }
      else
      {
        inputFileOS = MAC;
      }
    }
    else if (oneChar == LF)
    {
      ++isExistSpecificChar;
      inputFileOS = LIN;
    }
  }

  if (isExistSpecificChar > 0 && inputFileOS == NO_OS)
  {
    fprintf(stderr, "입력 파일이 MS 윈도우즈, 리눅스, 애플 OS 중 한 가지 OS에서 작성 된 파일이 아닙니다.\n");
    exit(0);
  }

  if (inputFileOS == NO_OS)
  {
    fprintf(stderr, "변환 할 필요가 없는 파일입니다.\n");
    exit(0);
  }

  printf("\n\ninput file os : %c\n\n", inputFileOS);

  if (inputFileOS == WIN)
  {
    switch (indicator)
    {
    case WIN:
      fprintf(stderr, "같은 OS에서 작성 된 파일이므로 변환 할 필요가 없는 파일입니다.\n");
      exit(0);
    case LIN:
      return WIN_TO_LIN;
    case MAC:
      return WIN_TO_MAC;
    }
  }
  else if (inputFileOS == LIN)
  {
    switch (indicator)
    {
    case WIN:
      return LIN_TO_WIN;
    case LIN:
      fprintf(stderr, "같은 OS에서 작성 된 파일이므로 변환 할 필요가 없는 파일입니다.\n");
      exit(0);
    case MAC:
      return LIN_TO_MAC;
    }
  }
  else if (inputFileOS == MAC)
  {
    switch (indicator)
    {
    case WIN:
      return MAC_TO_WIN;
    case LIN:
      return MAC_TO_LIN;
    case MAC:
      fprintf(stderr, "같은 OS에서 작성 된 파일이므로 변환 할 필요가 없는 파일입니다.\n");
      exit(0);
    }
  }

  return NO;
}

char getIndicator(char *s)
{
  int length;

  if ((length = strlen(s)) != 2)
  {
    printUsageMessage();
    exit(0);
  }

  if (s[0] != '-')
  {
    printUsageMessage();
    exit(0);
  }

  return s[1];
}

void convertToWin(FILE *fpin, FILE *fpout, int mode)
{
  int size;
  char oneChar;
  char outBuf[2];

  while (readOneByte(fpin, &oneChar) != -1)
  {
    if ((mode == LIN_TO_WIN && oneChar == LF) || (mode == MAC_TO_WIN && oneChar == CR))
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
      fprintf(stderr, "파일 출력 오류\n");
      break;
    }
  }
}

void convertToLin(FILE *fpin, FILE *fpout, int mode)
{
  int size;
  char oneChar;
  char outBuf[1];

  while (readOneByte(fpin, &oneChar) != -1)
  {
    if (oneChar == CR)
    {
      switch (mode)
      {
      case WIN_TO_LIN:
        size = 0;
        break;
      case MAC_TO_LIN:
        outBuf[0] = LF;
        size = 1;
        break;
      }
    }
    else
    {
      outBuf[0] = oneChar;
      size = 1;
    }
    if (size > 0)
      if (putBytes(fpout, outBuf, size) == -1)
      {
        fprintf(stderr, "파일 출력 오류\n");
        break;
      }
  }
}

void convertToMac(FILE *fpin, FILE *fpout, int mode)
{
  int size;
  char oneChar;
  char outBuf[2];

  while (readOneByte(fpin, &oneChar) != -1)
  {
    if (oneChar == LF)
    {
      switch (mode)
      {
      case WIN_TO_MAC:
        size = 0;
        break;
      case LIN_TO_MAC:
        outBuf[0] = CR;
        size = 1;
        break;
      }
    }
    else
    {
      outBuf[0] = oneChar;
      size = 1;
    }
    if (size > 0)
      if (putBytes(fpout, outBuf, size) == -1)
      {
        fprintf(stderr, "파일 출력 오류\n");
        break;
      }
  }
}

int main(int argc, char *argv[])
{
  int mode;
  FILE *fpin, *fpout;
  char *inputName, *outName;

  char targetOS;

  programName = argv[0];

  if (argc < 4)
  {
    fprintf(stderr, "Usage: %s -W|L|A input_file output_file\n", programName);
    exit(0);
  }

  inputName = argv[2];

  targetOS = getIndicator(argv[1]);

  printf("변경 전 : \n");
  printByHexCode(inputName);

  if ((mode = decideMode(inputName, targetOS)) == NO)
  {
    printf("%s: wrong OS indicator %c <only W, L, A accepted>", programName, targetOS);
    exit(0);
  }

  outName = argv[3];

  if ((fpin = fopen(inputName, "rb")) == NULL)
  {
    fprintf(stderr, "입력파일 %s를 열 수 없습니다.\n", inputName);
    return -1;
  }
  if ((fpout = fopen(outName, "wb")) == NULL)
  {
    fprintf(stderr, "출력파일 %s를 열 수 없습니다.\n", outName);
    return -1;
  }

  switch (targetOS)
  {
  case WIN:
    convertToWin(fpin, fpout, mode);
    break;
  case LIN:
    convertToLin(fpin, fpout, mode);
    break;
  case MAC:
    convertToMac(fpin, fpout, mode);
    break;
  }

  fclose(fpin);
  fclose(fpout);

  printf("\n\n변경 후 : \n");
  printByHexCode(outName);
  return 0;
}