#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
  element data;
  struct ListNode *link;
} ListNode;

int count_node(ListNode *phead, int data)
{
  int count = 0;

  ListNode *p;
  p = phead;
  while (p->link != NULL)
  {
    if (p->data == data)
    {
      count += 1;
    }
    p = p->link;
  }

  if (p->data == data)
  {
    count += 1;
  }

  return count;
}

int main(void)
{
  int nodeCount;

  printf("노드의 개수 : ");
  scanf("%d", &nodeCount);

  if (nodeCount <= 1)
  {
    printf("노드 갯수 오류 (2개 이상)");
  }
  else
  {
    ListNode *phead;
    phead = (ListNode *)malloc(sizeof(ListNode));
    phead->data = NULL;

    for (int i = 1; i < (nodeCount + 1); i++)
    {
      int inputData;
      printf("노드 #%d 데이터 : ", i);
      scanf("%d", &inputData);

      ListNode *p1;
      p1 = (ListNode *)malloc(sizeof(ListNode));
      p1->data = inputData;
      p1->link = NULL;

      if (i == 1)
      {
        phead->link = p1;
      }
      else
      {
        ListNode *fp;
        fp = phead;
        while (fp->link != NULL)
        {
          fp = fp->link;
        }

        fp->link = p1;
      }
    }

    int findData;
    printf("탐색 할 값을 입력하시오 : ");
    scanf("%d", &findData);
    printf("%d는 연결 리스트에서 %d번 나타납니다.", findData, count_node(phead, findData));
  }
  return 0;
}