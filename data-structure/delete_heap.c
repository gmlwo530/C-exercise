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

void delete_max_heap(HeapType *h)
{
  int parent, child;
  element item, temp;

  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size)
  {
    if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
    {
      child++;
    }
    if (temp.key >= h->heap[child].key)
      break;
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

int main(void)
{
  return 0;
}