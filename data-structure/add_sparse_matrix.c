#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 6
#define MAX_TERMS 37

typedef struct
{
  int row;
  int col;
  int value;
} element;

typedef struct
{
  element data[MAX_TERMS];
  int rows;
  int cols;
  int terms;
} SparseMatrix;

SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
  SparseMatrix c;
  int ca = 0, cb = 0, cc = 0;
  if (a.rows != b.rows || a.cols != b.cols)
  {
    printf("희소행렬 크기 에러\n");
    exit(1);
  }
  c.rows = a.rows;
  c.cols = a.cols;
  c.terms = 0;

  while (ca < a.terms && cb < b.terms)
  {
    int inda = a.data[ca].row * a.cols + a.data[ca].col;
    int indb = b.data[cb].row * b.cols + b.data[cb].col;
    if (inda < indb)
    {
      c.data[cc++] = a.data[ca++];
    }
    else if (inda == indb)
    {
      if ((a.data[ca].value + b.data[cb].value) != 0)
      {
        c.data[cc].row = a.data[ca].row;
        c.data[cc].col = a.data[ca].col;
        c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
      }
      else
      {
        ca++;
        cb++;
      }
    }
    else
    {
      c.data[cc++] = b.data[cb++];
    }
  }

  for (; ca < a.terms;)
    c.data[cc++] = a.data[ca++];
  for (; cb < b.terms;)
    c.data[cc++] = b.data[cb++];
  c.terms = cc;
  return c;
}

void print_matrix(SparseMatrix m)
{
  int terms = m.terms;

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      int isZero = 1;
      int val = 0;

      for (int a = 0; a < terms; a++)
      {
        if (i == m.data[a].row && j == m.data[a].col)
        {
          isZero = 0;
          val = m.data[a].value;
          break;
        }
      }

      if (isZero)
      {
        printf("0 ");
      }
      else
      {
        printf("%d ", val);
      }

      if (j == 5)
      {
        printf("\n");
      }
    }
  }
}

int main(void)
{
  SparseMatrix m1 = {{{0, 0, 1}, {1, 1, 1}, {2, 1, 1}, {3, 2, 1}, {4, 3, 1}, {5, 1, 2}, {5, 3, -1}}, 6, 6, 7};
  SparseMatrix m2 = {{{0, 0, 1}, {1, 0, 1}, {2, 1, 1}, {3, 2, 1}, {4, 0, 1}, {5, 0, 1}}, 6, 6, 6};

  SparseMatrix m3;
  m3 = sparse_matrix_add2(m1, m2);

  print_matrix(m3);

  return 0;
}