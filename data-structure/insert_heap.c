#include <stdio.h>

typedef struct
{
  int key;
} element;

typedef struct
{
  element heap[200];
  int heap_size;
} HeapType;

void insert_max_heap(HeapType *h, element item)
{
  int i;
  i = ++(h->heap_size);

  while ((i != 1) && (item.key > h->heap[i / 2].key))
  {
    h->heap[i] = h->heap[i / 2];
    i /= 2;
  }
  h->heap[i] = item;
}

int main(void)
{
  return 0;
}