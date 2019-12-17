#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left, *right;
} TreeNode;

int cal_node_count(TreeNode *root)
{
  int count = 0;
  if (root != NULL)
  {
    count = 1 + cal_node_count(root->left) + cal_node_count(root->right);
  }
  return count;
}

int cal_leaf_count(TreeNode *root)
{
  int count = 0;

  if (root != NULL)
  {
    if (root->left == NULL && root->right == NULL)
    {
      return 1;
    }
    else
    {
      count = cal_leaf_count(root->left) + cal_leaf_count(root->right);
    }
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

  printf("노드 갯수는 %d입니다. \n", cal_node_count(&n1));
  printf("단말 노드갯수는 %d입니다. \n", cal_leaf_count(&n1));
  return 0;
}