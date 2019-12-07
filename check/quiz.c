#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_WORD_SIZE = 1000;
int MAX_STRING_SIZE = 10000;

int myWordArrLen = 0;

typedef struct word
{
  char *name;
  int count;
} MyWord;

MyWord makeMyWord(char *word)
{
  MyWord newMyWord;
  newMyWord.name = word;
  newMyWord.count = 1;
  return newMyWord;
}

void swap(MyWord myWords[], int i, int j)
{
  MyWord tmp;
  tmp = myWords[i];
  myWords[i] = myWords[j];
  myWords[j] = tmp;
}

void sortByMyWordAlphabet(MyWord myWords[], int index)
{
  if (myWords[index].name[0] > myWords[index + 1].name[0])
  {
    swap(myWords, index, index + 1);
  }
}

void sortByMyWordLength(MyWord myWords[], int index)
{
  if (strlen(myWords[index].name) > strlen(myWords[index + 1].name))
  {
    swap(myWords, index, index + 1);
  }
  else if (strlen(myWords[index].name) == strlen(myWords[index + 1].name))
  {
    sortByMyWordAlphabet(myWords, index);
  }
}

void sortByCount(MyWord myWords[])
{
  int i, j;

  for (i = 0; i < (myWordArrLen - 1); i++)
  {
    for (j = 0; j < (myWordArrLen - i) - 1; j++)
    {
      if (myWords[j].count < myWords[j + 1].count)
      {
        swap(myWords, j, j + 1);
      }
      else if (myWords[j].count == myWords[j + 1].count)
      {
        sortByMyWordLength(myWords, j);
      }
    }
  }
}

// 같은 단어를 찾으면 그 단어가 있는 배열의 index 반환, 못 찾으면 -1을 반환
int findSameWord(MyWord myWords[], char *word)
{
  for (int j = 0; j < myWordArrLen; j++)
  {
    if (strcmp(myWords[j].name, word) == 0)
    {
      return j;
    }
  }
  return -1;
}

int isNumber(char *word)
{
  for (int i = 0; i < strlen(word); i++)
  {
    if (word[i] > 47 && word[i] < 58)
    {
      return 1;
    }
  }
  return 0;
}

void printMyWords(MyWord myWords[], int totalWordCnt)
{
  printf("Number of different words = %d\n", totalWordCnt);
  for (int l = 0; l < myWordArrLen; l++)
  {
    printf("%04d:%4d%5lu %s\n", l + 1, myWords[l].count, strlen(myWords[l].name), myWords[l].name);
  }
}

int main(void)
{
  char tmpBuf[MAX_STRING_SIZE];
  char buf[MAX_STRING_SIZE];
  MyWord myWords[MAX_WORD_SIZE];
  char *seps = " \t\n";
  char *word;
  int totalWordCnt = 0;

  while (fgets(tmpBuf, MAX_STRING_SIZE, stdin) != NULL)
  {
    if (strlen(buf) == 0)
    {
      strcpy(buf, tmpBuf);
    }
    else
    {
      strcat(buf, tmpBuf);
    }
  }

  word = strtok(buf, seps);
  if (word == NULL)
  {
    printf("텍스트 파일에 단어가 없습니다.");
    return 0;
  }
  ++totalWordCnt;

  if (isNumber(word) == 0)
  {
    myWords[myWordArrLen++] = makeMyWord(word);
  }

  while ((word = strtok(NULL, seps)) != NULL)
  {
    ++totalWordCnt;

    int index = findSameWord(myWords, word);

    if (index >= 0)
    {
      myWords[index].count += 1;
    }
    else
    {
      if (isNumber(word) == 0)
      {
        myWords[myWordArrLen++] = makeMyWord(word);
      }
      // myWords[myWordArrLen++] = makeMyWord(word);
    }
  }

  sortByCount(myWords);
  printMyWords(myWords, totalWordCnt);
  return 0;
}