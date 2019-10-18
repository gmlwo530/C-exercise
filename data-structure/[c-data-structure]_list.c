// C언어로 쉽게 풀어 쓴 자료구조 6장 리스트
#include <stdio.h>
#include <stdlib.h>

/*
리스트 ADT
객체 : n개의 element 형으로 구성된 순서 있는 모임
연산 : add_last(list, item), add_first(list, item), add(list, post, item) ...
*/

/*
리스트 구현 방법

- 배열을 이용하는 방법 : 구현이 간단하지만, 항목의 개수가 제한되어 있고, 삽입, 삭제 시 오버헤드
- 연결 리스트를 이용하는 방법 : 구현 복잡하지만, 삽입 삭제가 효율적, 크기가 제한되지 않음
*/

// 배열을 이용하는 방법
typedef int element;
typedef struct
{
  int list[100];
  int length;
} ArrayListType;

// 연결 리스트를 이용하는 방법(노드)
typedef struct
{
  element data;
  struct ListNode *link;
} ListNode;

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
  if (*phead == NULL)
  {
    new_node->link = NULL;
    *phead = new_node;
  }
  else if (p == NULL)
  {
    new_node->link = *phead;
    *phead = new_node;
  }
  else
  {
    new_node->link = p->link;
    p->link = new_node;
  }
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
  if (p == NULL)
  {
    *phead = (*phead)->link;
  }
  else
  {
    p->link = removed->link;
  }

  free(removed);
}

ListNode *search(ListNode *head, int x)
{
  ListNode *p;
  p = head;
  while (p != NULL)
  {
    if (p->data == x)
      return p;
    p = p->link;
  }
  return p;
}

ListNode *concat(ListNode *head1, ListNode *head2)
{
  ListNode *p;
  if (head1 == NULL)
    return head2;
  else if (head2 == NULL)
    return head2;
  else
  {
    p = head1;
    while (p->link != NULL)
      p = p->link;
    p->link = head2;
    return head1;
  }
}

ListNode *reverse(ListNode *head)
{
  ListNode *p, *q, *r;
  p = head;
  q = NULL;

  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->link;
    q->link = r;
  }

  return q;
}

// 원형 리스트

void circle_insert_first(ListNode **phead, ListNode *node)
{
  if (*phead == NULL)
  {
    *phead = node;
    node->link = node;
  }
  else
  {
    node->link = (*phead)->link;
    (*phead)->link = node;
  }
}

void circle_insert_last(ListNode **phead, ListNode *node)
{
  if (*phead == NULL)
  {
    *phead = node;
    node->link = node;
  }
  else
  {
    node->link = (*phead)->link;
    (*phead)->link = node;
    *phead = node;
  }
}

// 이중 연결 리스트

typedef struct DlistNode
{
  element data;
  struct DlistNode *llink;
  struct DlistNode *rlink;
} DlistNode;

void dinsert_node(DlistNode *before, DlistNode *new_node)
{
  new_node->llink = before;
  new_node->rlink = before->rlink;
  before->rlink->llink = new_node;
  before->rlink = new_node;
}

void dremove_node(DlistNode *head_node, DlistNode *removed)
{
  if (removed == head_node)
    return;
  removed->llink->rlink = removed->rlink;
  removed->rlink->llink = removed->llink;
}

int main(void)
{
  return 0;
}