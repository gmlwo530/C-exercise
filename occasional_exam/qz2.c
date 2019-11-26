#include <stdio.h>
#include <string.h>

int MAX_WORD_SIZE = 1000;
int MAX_STRING_SIZE = 10000;

typedef struct word
{
  char *name;
  int count;
} MyWord;

void swap(MyWord myWords[], int i, int j)
{
  MyWord tmp;
  tmp = myWords[i];
  myWords[i] = myWords[j];
  myWords[j] = tmp;
}

void sortByCount(MyWord myWords[], int len)
{
  int i, j;

  for (i = 0; i < (len - 1); i++)
  {
    for (j = 0; j < (len - i) - 1; j++)
    {
      if (myWords[j].count < myWords[j + 1].count)
      {
        swap(myWords, j, j + 1);
      }
      else if (myWords[j].count == myWords[j + 1].count)
      {
        if (strlen(myWords[j].name) > strlen(myWords[j + 1].name))
        {
          swap(myWords, j, j + 1);
        }
        else if (strlen(myWords[j].name) == strlen(myWords[j + 1].name))
        {
          if (myWords[j].name[0] > myWords[j + 1].name[0])
          {
            swap(myWords, j, j + 1);
          }
        }
      }
    }
  }
}

int main(void)
{
  char buf[MAX_STRING_SIZE];
  char buf2[MAX_STRING_SIZE];
  MyWord myWords[MAX_WORD_SIZE];
  char *seps = " \t\n";
  char *word;
  int totalWordCnt = 0;
  int wordArrLen = 0;
  int ret = 0;

  while (fgets(buf, MAX_STRING_SIZE, stdin) != NULL)
  {
    if (ret > 0)
    {
      strcat(buf2, buf);
    }
    else
    {
      strncpy(buf2, buf, MAX_STRING_SIZE);
    }
    ret++;
  }
  word = strtok(buf2, seps);
  ++totalWordCnt;
  MyWord myWord;
  myWord.name = word;
  myWord.count = 1;
  myWords[wordArrLen++] = myWord;

  while ((word = strtok(NULL, seps)) != NULL)
  {
    int isExist = 0;
    int target;
    for (int j = 0; j < wordArrLen; j++)
    {
      if (strcmp(myWords[j].name, word) == 0)
      {
        isExist = 1;
        target = j;
      }
    }

    if (isExist)
    {
      myWords[target].count += 1;
    }
    else
    {
      MyWord myWord;
      myWord.name = word;
      myWord.count = 1;
      myWords[wordArrLen++] = myWord;
    }

    ++totalWordCnt;
  }

  printf("Number of words = %d\n", totalWordCnt);

  sortByCount(myWords, wordArrLen);

  for (int l = 0; l < wordArrLen; l++)
  {
    printf("%05d:%6d %s\n", l + 1, myWords[l].count, myWords[l].name);
  }
  return 0;
}