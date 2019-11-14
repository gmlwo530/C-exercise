#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef struct TreeNode
{
  int data;
  struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode *element;

typedef struct {
  element data[MAX_QUEUE_SIZE];
  int front, rear;
}QueueType;

int maxNum, minNum;


void max(TreeNode *root)
{
  if (root != NULL)
  {
    if (maxNum < root->data)
      maxNum = root->data;
    max(root->left);
    max(root->right);
  }
}

void min(TreeNode *root)
{
  if (root != NULL)
  {
    if (minNum > root->data)
      minNum = root->data;
    min(root->left);
    min(root->right);
  }
}


void error(char *message){
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void init_queue(QueueType *q){
  q->front = q->rear =0;
}

int is_empty(QueueType *q){
  return (q->front == q->rear);
}

int is_full(QueueType *q){
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
  if (is_full(q))
    error("큐가 포화상태입니다");
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->data[q->rear] = item;
}

element dequeue(QueueType *q){
  if (is_empty(q))
    error("큐가 공백상태입니다");
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->data[q->front];
}

void level_order(TreeNode *ptr){
  QueueType q;

  init_queue(&q);
  if (ptr == NULL) return;
  enqueue(&q, ptr);
  while(!is_empty(&q)){
    ptr = dequeue(&q);
    printf(" [%d] ", ptr->data);
    if (ptr->left)
      enqueue(&q, ptr->left);
    if (ptr->right)
      enqueue(&q, ptr->right);
  }
}

int main(void)
{
  TreeNode *n[10];
  for (int i = 0; i < 10; i++)
  {
    n[i] = (TreeNode *)malloc(sizeof(TreeNode));
  }

  n[0]->data = 8;
  n[0]->left = n[1];
  n[0]->right = n[2];

  n[1]->data = 5;
  n[1]->left = n[3];
  n[1]->right = n[4];

  n[2]->data = 4;
  n[2]->left = NULL;
  n[2]->right = n[5];

  n[3]->data = 9;
  n[3]->left = NULL;
  n[3]->right = NULL;

  n[4]->data = 7;
  n[4]->left = n[6];
  n[4]->right = n[7];

  n[5]->data = 11;
  n[5]->left = n[8];
  n[5]->right = NULL;

  n[6]->data = 1;
  n[6]->left = NULL;
  n[6]->right = NULL;

  n[7]->data = 12;
  n[7]->left = n[9];
  n[7]->right = NULL;

  n[8]->data = 3;
  n[8]->left = NULL;
  n[8]->right = NULL;

  n[9]->data = 2;
  n[9]->left = NULL;
  n[9]->right = NULL;

  minNum = n[0]->data;
  min(n[0]);
  printf("최소값=%d\n", minNum);
  maxNum = n[0]->data;
  max(n[0]);
  printf("최대값=%d\n", maxNum);

  printf("레벨 순회=");
  level_order(n[0]);

  return 0;
}