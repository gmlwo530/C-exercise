#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 6

#define MAX_STACK_SIZE 100

typedef struct
{
  int r;
  int c;
} element;

typedef struct
{
  element stack[MAX_STACK_SIZE];
  int top;
} StackType;

void init_stack(StackType *s)
{
  s->top = -1;
}

int is_empty(StackType *s)
{
  return s->top == -1;
}

int is_pull(StackType *s)
{
  return s->top == MAX_STACK_SIZE;
}

void push(StackType *s, element item)
{
  if (is_pull(s))
  {
    printf("Stack is Full\n");
    return;
  }
  else
  {
    s->stack[++(s->top)] = item;
  }
}

element pop(StackType *s)
{
  if (is_empty(s))
  {
    printf("Stack is Empty\n");
    exit(1);
  }
  return s->stack[(s->top)--];
}

element peek(StackType *s)
{
  if (is_empty(s))
  {
    printf("Stack is Empty\n");
    exit(1);
  }
  return s->stack[(s->top)];
}

int stack_size(StackType *s)
{
  return (s->top) + 1;
}

element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}};

void push_loc(StackType *s, int r, int c)
{
  if (r < 0 || c < 0 || r >= MAX_STACK_SIZE || c >= MAX_STACK_SIZE)
    return;

  if (maze[r][c] != '1' && maze[r][c] != '.')
  {
    element temp = {r, c};
    push(s, temp);
  }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
  printf("\n");
  for (int r = 0; r < MAZE_SIZE; r++)
  {
    for (int c = 0; c < MAZE_SIZE; c++)
    {
      printf("%c", maze[r][c]);
    }
    printf("\n");
  }
}

int main(void)
{
  int r, c;
  StackType s;

  init_stack(&s);
  here = entry;

  while (maze[here.r][here.c] != 'x')
  {
    r = here.r;
    c = here.c;
    maze[r][c] = '.';
    maze_print(maze);
    push_loc(&s, r - 1, c);
    push_loc(&s, r + 1, c);
    push_loc(&s, r, c - 1);
    push_loc(&s, r, c + 1);
    if (is_empty(&s))
    {
      printf("실패\n");
      return 0;
    }
    else
      here = pop(&s);
  }
  printf("성공\n");

  return 0;
}