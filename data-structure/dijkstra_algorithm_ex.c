#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType
{
  int n;
  int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int setS[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;
  for (i = 0; i < n; i++)
  {
    if (distance[i] < min && !found[i])
    {
      min = distance[i];
      minpos = i;
    }
  }
  return minpos;
}

void print_status(GraphType *g, int foundedCount)
{
  static int step = 1;
  printf("STEP %d: ", step++);
  printf("distance :");
  for (int i = 0; i < g->n; i++)
  {
    if (distance[i] == INF)
    {
      printf(" * ");
    }
    else
    {
      printf("%2d ", distance[i]);
    }
  }
  printf("\n");
  printf("               S :");
  for (int i = 0; i < foundedCount; i++)
  {
    if (setS[i] == 1)
    {
      printf("%2c", 's');
    }
    else if (setS[i] == 8)
    {
      printf("%2c", 't');
    }
    else
    {
      printf("%2d", setS[i]);
    }
  }
  printf("\n\n");
}

void shortest_path(GraphType *g, int start)
{
  int i, u, w;
  int foundedCount = 1;
  for (i = 0; i < g->n; i++)
  {
    distance[i] = g->weight[start][i];
    found[i] = FALSE;
  }
  found[start] = TRUE;
  distance[start] = 0;
  setS[start] = 1;
  for (i = 0; i < g->n; i++)
  {
    print_status(g, foundedCount);
    u = choose(distance, g->n, found);
    found[u] = TRUE;

    setS[foundedCount++] = u + 1;

    for (w = 0; w < g->n; w++)
    {
      if (!found[w])
      {
        if (distance[u] + g->weight[u][w] < distance[w])
        {
          distance[w] = distance[u] + g->weight[u][w];
        }
      }
    }
  }
}

int main(void)
{
  GraphType g = {
      8,
      {{0, 9, INF, INF, INF, 14, 15, INF},
       {INF, 0, 24, INF, INF, INF, INF, INF},
       {INF, INF, 0, INF, 2, INF, INF, 19},
       {INF, INF, 6, 0, INF, INF, INF, 6},
       {INF, INF, INF, 11, 0, INF, INF, 16},
       {INF, INF, 18, INF, 30, 0, 5, INF},
       {INF, INF, INF, INF, 20, INF, 0, 44},
       {INF, INF, INF, INF, INF, INF, INF, 0}}};

  shortest_path(&g, 0);
  return 0;
}