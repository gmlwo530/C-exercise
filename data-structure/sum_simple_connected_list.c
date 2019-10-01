#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
  element data;
  struct ListNode *link;
} ListNode;

int sum_node(ListNode *phead)
{
  int sum = 0;
  ListNode *p2;
  p2 = phead;

  while (p2->link != NULL)
  {
    sum += p2->data;
    p2 = p2->link;
  }

  sum += p2->data;

  return sum;
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

    printf("연결 리스트의 데이터 합 : %d", sum_node(phead));
  }
  return 0;
}