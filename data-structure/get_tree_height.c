#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

typedef struct TreeNode
{
  int data;
  struct TreeNode *left, *right;
} TreeNode;

int cal_node_height(TreeNode *root)
{
  int count = 0;
  if (root != NULL)
  {
    count = 1 + max(cal_node_height(root->left), cal_node_height(root->right));
  }
  return count;
}

int main(void)
{
  TreeNode n5 = {500, NULL, NULL};
  TreeNode n4 = {200, NULL, NULL};
  TreeNode n3 = {100, &n4, &n5};
  TreeNode n2 = {50, NULL, NULL};
  TreeNode n1 = {0, &n2, &n3};

  printf("노드 높이는 %d입니다. \n", cal_node_height(&n1));
  return 0;
}