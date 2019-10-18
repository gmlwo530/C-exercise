// C언어로 쉽게 풀어 쓴 자료구조 2장 배열, 구조체, 포인터
#include <stdio.h>

/*
배열 ADT
객체 : <인덱스, 요소> 쌍들의 집합
연산 : create(n), retrieve(A,i), store(A,i,item)
*/

/*
배열 vs 구조체
구조체는 타입이 다른 데이터를 하나로 묶음
배열은 타입이 같은 데이터들을 하나로 묶음
*/

// 구조체 선언 방법 1
struct studentTag
{
  char name[10];
  int age;
};

struct studentTag sTag;

// 구조체 선언 방법 2
typedef struct
{
  char name[10];
  int age;
  struct student2 *link;
} student2;

student2 s2;

int main(void)
{
  return 0;
}