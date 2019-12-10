#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CR '\r'
#define LF '\n'
//W->L 1,   L->W 0  OTHER -1

int getbyte(FILE *fp, unsigned char *byte)
{
  if (fread(byte, 1, 1, fp) < 1) //읽힐 시 1반환
    return 0;
  else
    return 1;
}
int putbyte(FILE *fp, unsigned char *byte, int size)
{
  if ((fwrite(byte, 1, size, fp)) != size)
    return 0;
  else
    return 1;
}
int versioncheck(char *filename)
{
  FILE *file;
  int mode;
  unsigned char byte;
  if ((file = fopen(filename, "rb")) == NULL)
  {
    fprintf(stderr, "입려파일 %s를 열 수 없습니다.\n", filename);
    mode = -1;
    return mode;
  }
  while (getbyte(filename, &byte) > 0)
  {
    if (byte == CR)
    {
      mode = 1;
      return mode;
    }
    if (byte == LF)
    {
      mode = 0;
      return mode;
    }
  }
}

void reversestring(char *arr)
{
  int i;
  char temp;
  int len = strlen(arr);
  for (i = 0; i < len / 2; i++)
  {
    temp = arr[i];
    arr[i] = arr[len - 1 - i];
    arr[len - 1 - i] = temp;
  }
}

int findindex(char *arr, char index)
{
  int len = strlen(arr);
  int i;
  for (i = 0; i < len; i++)
  {
    if (arr[i] == index)
      return i;
  }
  return -1;
}
char *findfilename(char *arr)
{
  char *temp;
  int num;
  temp = (char *)calloc(strlen(arr) + 1, 1);
  strcpy(temp, arr);
  reversestring(arr);
  if ((num = findindex(temp, '\\')) > 0)
    temp[num] = 0;
  reversestring(temp);
  return temp;
}

char *findoutfile(char *arr, int mode)
{
  char *add, *outfile, *temp;
  int idx;
  if (mode == 1)
    add = "_lin";
  else
    add = "_win";
  temp = findfilename(arr);
  outfile = (char *)calloc(strlen(temp) + strlen(add), sizeof(char));
  if ((idx = findindex(temp, '.')) < 0)
  {
    strcpy(outfile, temp);
    strcat(outfile, add);
  }
  else
  {
    strncpy(outfile, temp, idx);
    strcat(outfile, add);
    strcat(outfile, &temp[idx]);
  }
  free((void *)temp);
  return outfile;
}

int main(int argc, char *argv[])
{
  FILE *in;
  FILE *out;
  char *outfp;
  int size, mode;
  unsigned char byte, outbuf[2];
  printf("%s\n", argv[1]);
  mode = versioncheck(argv[1]);
  if (mode == -1)
  {
    printf("변환 모드를 결정할 수 없습니다.\n");
    return -1;
  }

  outfp = findoutfile(argv[1], mode);
  if ((in = fopen(argv[1], "rt")) == NULL)
  {
    printf("%s파일을 열 수 없습니다.\n", argv[1]);
    return -1;
  }
  if ((out = fopen(outfp, "wt")) == NULL)
  {
    printf("%s파일을 열 수 없습니다.\n", outfp);
    return -1;
  }

  if (mode == 0)
  {
    while (getbyte(in, &byte) > 0)
    {
      if (byte == LF)
      {
        outbuf[0] = CR;
        outbuf[1] = LF;
        size = 2;
      }
      else
      {
        outbuf[0] = byte;
        size = 1;
      }
      putbyte(out, &byte, size);
    }
  }
  else
    while (getbyte(in, &byte) > 0)
    {
      if (byte == CR)
        size = 0;
      else
      {
        outbuf[0] = byte;
        size = 1;
      }
      if (size > 0)
        putbyte(out, &byte, size);
    }
  fclose(in);
  fclose(out);
  return 0;
}