#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
  element data;
  struct ListNode *link;
} ListNode;

ListNode *alternate(ListNode *ahead, ListNode *bhead)
{
  ListNode *phead;
  phead = (ListNode *)malloc(sizeof(ListNode));
  phead->data = NULL;
  phead->link = NULL;

  ListNode *ap, *bp, *p;
  ap = ahead->link;
  bp = bhead->link;

  p = phead;

  while ((ap->link != NULL) && (bp->link != NULL))
  {
    p->link = ap;
    p = p->link;
    ap = ap->link;

    p->link = bp;
    p = p->link;
    bp = bp->link;
  }

  if (ap->link == NULL && bp->link == NULL)
  {
    p->link = ap;
    p = p->link;

    p->link = bp;
  }
  else if (ap->link == NULL)
  {
    p->link = ap;
    p = p->link;
    while (bp != NULL)
    {
      p->link = bp;
      p = p->link;
      bp = bp->link;
    }
  }
  else if (bp->link == NULL)
  {
    int bIsNotDone = 1;

    while (ap != NULL)
    {
      p->link = ap;
      p = p->link;
      ap = ap->link;

      if (bIsNotDone)
      {
        p->link = bp;
        p = p->link;
        bIsNotDone = 0;
      }
    }
  }

  return phead;
}

void makeList(ListNode *phead, int nodeCount, char listName)
{
  for (int i = 1; i < (nodeCount + 1); i++)
  {
    int inputData;
    printf("%c 노드 #%d 데이터 : ", listName, i);
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
}

void printList(ListNode *phead)
{
  printf("C 리스트 \n");
  ListNode *p;
  p = phead;
  while (p->link != NULL)
  {
    if (p->data != NULL)
      printf("%d ", p->data);
    p = p->link;
  }
  printf("%d \n", p->data);
}

int main(void)
{
  int nodeCount;

  printf("A 리스트 노드의 개수 : ");
  scanf("%d", &nodeCount);

  if (nodeCount < 1)
  {
    printf("노드 개수 오류");
    exit(1);
  }

  ListNode *ahead;
  ahead = (ListNode *)malloc(sizeof(ListNode));
  ahead->data = NULL;

  makeList(ahead, nodeCount, 'A');

  printf("B 리스트 노드의 개수 : ");
  scanf("%d", &nodeCount);

  if (nodeCount < 1)
  {
    printf("노드 개수 오류");
    exit(1);
  }

  ListNode *bhead;
  bhead = (ListNode *)malloc(sizeof(ListNode));
  bhead->data = NULL;

  makeList(bhead, nodeCount, 'B');

  printf("A 리스트 : ");
  printList(ahead);
  printf("B 리스트 : ");
  printList(bhead);

  ListNode *chead;
  chead = alternate(ahead, bhead);

  printList(chead);

  return 0;
}