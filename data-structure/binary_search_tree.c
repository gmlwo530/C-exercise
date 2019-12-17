#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
  element key;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode *search(TreeNode *node, int key)
{
  if (node == NULL)
    return NULL;
  if (key == node->key)
    return node;
  else if (key < node->key)
    return search(node->left, key);
  else
    return search(node->right, key);
}

TreeNode *new_node(int item)
{
  TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void insert_node(TreeNode **root, int key)
{
  TreeNode *p, *t; //p는 부모노드, t는 현재노드
  TreeNode *n;
  t = *root;
  p = NULL;
  while (t != NULL)
  {
    if (key == t->key)
      return;
    p = t;
    if (key < t->key)
      t = t->left;
    else
      t = t->right;
  }
  n = (TreeNode *)malloc(sizeof(TreeNode));
  if (n == NULL)
    return;
  n = new_node(key);
  if (p != NULL)
    if (key < p->key)
      p->left = n;
    else
      p->right = n;
  else
    *root = n;
}

TreeNode *min_value_node(TreeNode *node)
{
  TreeNode *current = node;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

void delete_node(TreeNode **root, int key)
{
  TreeNode *p, *child, *succ, *succ_p, *t;
  p = NULL;
  t = *root;
  while (t != NULL && t->key != key)
  {
    p = t;
    t = (key < t->key) ? t->left : t->right;
  }

  if (t == NULL)
  {
    printf("Key is not in the tree");
    return;
  }

  if ((t->left == NULL) && (t->right == NULL))
  {
    if (p != NULL)
    {
      if (p->left == t)
        p->left = NULL;
      else
        p->right = NULL;
    }
    else
      *root = NULL;
  }
  else if ((t->left == NULL) && (t->right == NULL))
  {
    child = (t->left != NULL) ? t->left : t->right;
    if (p != NULL)
    {
      if (p->left = t)
        p->left = child;
      else
        p->right = child;
    }
    else
      *root = NULL;
  }
  else
  {
    succ_p = t;
    succ = t->right;
    while (succ->left != NULL)
    {
      succ_p = succ;
      succ = succ->left;
    }
    if (succ_p->right == succ)
    {
      succ_p->right = succ->right;
    }
    else
    {
      succ_p->left = succ->right;
    }

    t->key = succ->key;
    t = succ;
  }
  free(t);
}

int main(void)
{
  return 0;
}