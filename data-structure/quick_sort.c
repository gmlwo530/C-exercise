#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 50

void makeRandomArr(int arr[])
{
  srand(time(NULL));

  for (int i = 0; i < ARR_SIZE; i++)
  {
    arr[i] = (rand() % 10000) + 1;
  }
}

void printArr(int arr[])
{
  for (int i = 0; i < ARR_SIZE; i++)
  {
    printf("%d ", arr[i]);
  }
}

void swap(int arr[], int a, int b)
{
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int partition(int arr[], int start, int end)
{
  int low = start;
  int high = end + 1;
  int pivot = arr[start];

  do
  {
    do
    {
      low++;
    } while (low <= end && arr[low] < pivot);

    do
    {
      high--;
    } while (high >= start && arr[high] > pivot);

    if (low < high)
    {
      swap(arr, low, high);
    }

  } while (low < high);

  swap(arr, start, high);

  return high;
}

void quickSort(int arr[], int start, int end)
{
  if (start < end)
  {
    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
}

int main(void)
{
  int arr[ARR_SIZE];
  makeRandomArr(arr);
  printf("Unsorted : ");
  printArr(arr);
  quickSort(arr, 0, ARR_SIZE - 1);
  printf("\n\n");
  printf("Sorted : ");
  printArr(arr);
  return 0;
}