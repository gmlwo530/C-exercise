#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode
{
  element data;
  struct ListNode *link;
} ListNode;

ListNode *search_list(ListNode *head, element x)
{
  ListNode *p = head;
  ListNode *pre = NULL;

  while (p != NULL)
  {
    if (p->data == x)
      return pre;
    pre = p;
    p = p->link;
  }

  return NULL;
}

ListNode *insert_first(ListNode *head, element data)
{
  ListNode *p = (ListNode *)malloc(sizeof(ListNode));
  p->data = data;
  p->link = head;
  head = p;
  return head;
}

void print_list(ListNode *head)
{
  for (ListNode *p = head; p != NULL; p = p->link)
    printf("%d->", p->data);

  printf("NULL \n");
}

ListNode *delete (ListNode *head, ListNode *pre)
{
  if (pre == NULL)
  {
    head = head->link;
  }
  else
  {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
  }

  return head;
}

int main(void)
{
  ListNode *head = NULL;
  ListNode *pre = NULL;
  head = insert_first(head, 10);
  head = insert_first(head, 20);
  head = insert_first(head, 30);
  head = insert_first(head, 40);

  print_list(head);

  pre = search_list(head, 20);

  head = delete (head, pre);
  print_list(head);

  return 0;
}