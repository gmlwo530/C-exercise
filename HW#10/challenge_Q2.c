#include <stdio.h>
#include <stdlib.h>

typedef struct book
{
  char author[100];
  char name[100];
  int pageNum;
} Book;

int main(void)
{
  Book arr[3];
  char ch;
  printf("도서 정보 입력\n");

  for (int i = 0; i < 3; i++)
  {
    Book *book;
    book = (Book *)malloc(sizeof(Book));

    char dummy[3];

    printf("저자: ");
    fgets(book->author, sizeof(book->author), stdin);
    printf("제목: ");
    fgets(book->name, sizeof(book->name), stdin);
    printf("페이지 수: ");
    scanf("%d", &(book->pageNum));
    fgets(dummy, sizeof(dummy), stdin);

    arr[i] = *book;
  }

  printf("도서 정보 출력\n");

  for (int i = 0; i < 3; i++)
  {
    printf("book %d\n", i + 1);
    printf("저자: %s", arr[i].author);
    printf("제목: %s", arr[i].name);
    printf("페이지 수: %d\n", arr[i].pageNum);
  }
  return 0;
}