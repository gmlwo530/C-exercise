#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
  int coef;
  int expon;
  struct ListNode *link;
} ListNode;

typedef struct ListHeader
{
  int length;
  ListNode *head;
  ListNode *tail;
} ListHeader;

void init(ListHeader *plist)
{
  plist->length = 0;
  plist->head = plist->tail = NULL;
}

void insert_node_last(ListHeader *plist, int coef, int expon)
{
  ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
  if (temp == NULL)
    perror("메모리 할당 에러");
  temp->coef = coef;
  temp->expon = expon;
  temp->link = NULL;

  if (plist->tail == NULL)
  {
    plist->head = plist->tail = temp;
  }
  else
  {
    plist->tail->link = temp;
    plist->tail = temp;
  }
  plist->length++;
}

void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3)
{
  ListNode *a = plist1->head;
  ListNode *b = plist2->head;
  int sum;
  while (a != NULL && b != NULL)
  {
    if (a->expon == b->expon)
    {
      sum = a->coef + b->coef;
      if (sum != 0)
        insert_node_last(plist3, sum, a->expon);
      a = a->link;
      b = b->link;
    }
    else if (a->expon > b->expon)
    {
      insert_node_last(plist3, a->coef, a->expon);
      a = a->link;
    }
    else
    {
      insert_node_last(plist3, b->coef, b->expon);
      b = b->link;
    }
  }

  for (; a != NULL; a = a->link)
    insert_node_last(plist3, a->coef, a->expon);

  for (; b != NULL; b = b->link)
    insert_node_last(plist3, b->coef, b->expon);
}

void poly_print(ListHeader *plist)
{
  ListNode *p = plist->head;
  for (; p != NULL; p = p->link)
  {
    printf("%d %d\n", p->coef, p->expon);
  }
}

int main(void)
{
  ListHeader list1, list2, list3;

  init(&list1);
  init(&list2);
  init(&list3);

  insert_node_last(&list1, 3, 6);
  insert_node_last(&list1, 7, 3);
  insert_node_last(&list1, -2, 2);
  insert_node_last(&list1, -9, 0);

  insert_node_last(&list2, -2, 6);
  insert_node_last(&list2, -4, 4);
  insert_node_last(&list2, 6, 2);
  insert_node_last(&list2, 6, 1);
  insert_node_last(&list2, 1, 0);

  poly_add(&list1, &list2, &list3);
  poly_print(&list3);

  return 0;
}