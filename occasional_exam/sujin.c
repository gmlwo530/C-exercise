#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_count 1000

typedef struct word
{
  char *word;
  int count;
} Word;

int findword(char *arr, Word *wdb, int count)
{
  int i;
  for (i = 0; i < count; i++)
  {
    if (strcmp(arr, wdb[i].word) == 0)
    {
      return i;
    }
  }
  return -1;
}
void initialize(Word *data)
{
  int i = 0;
  for (i = 0; i < max_count; i++)
  {
    data[i].word = (char *)NULL;
    data[i].count = 0;
  }
}
void saveword(char *arr, Word *wdb)
{
  int i = 0;
  while (wdb[i].count != 0)
    i++;
  wdb[i].word = (char *)malloc(strlen(arr) + 1);
  strcpy(wdb[i].word, arr);
  wdb[i].count = 1;
}

void showword(Word *wdb, int wordcount)
{
  int i = 0;
  printf("Number of words : %d\n", wordcount);
  while (wdb[i].word != (char *)NULL)
  {
    printf("%06d : ", i + 1);
    printf("%8d  %s\n", wdb[i].count, wdb[i].word);
    i++;
  }
}

int main()
{
  Word wdb[max_count];
  int wordcount = 0;
  int wordLen = 0;
  int check, ret = 0;
  FILE *fp;
  char path[20];
  char arr[25];
  printf("파일명 입력 : ");
  scanf("%s", path);
  fp = fopen(path, "rt");
  if (fp == NULL)
  {
    printf("파일 오픈 실패!\n");
    return -1;
  }
  initialize(wdb);

  while (1)
  {
    ret = fscanf(fp, "%s", arr);

    if (ret == EOF)
      break;

    if (wordcount == 0)
    {
      saveword(arr, wdb);
      wordcount++;
      wordLen++;
      continue;
    }

    check = findword(arr, wdb, wordLen);

    if (check < 0)
    {
      saveword(arr, wdb);
      wordLen++;
    }
    else
    {
      wdb[check].count++;
    }
    wordcount++;
  }

  showword(wdb, wordcount);
  fclose(fp);
  return 0;
}