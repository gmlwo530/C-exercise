#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(int arr[], int length, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < length && arr[left] > arr[largest])
    largest = left;

  if (right < length && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, length, largest);
  }
}

void heapSort(int arr[], int length)
{
  for (int i = length / 2 - 1; i >= 0; i--)
  {
    heapify(arr, length, i);
  }

  for (int i = length - 1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

int main(void)
{
  int arr[] = {30, 10, 69, 2, 16, 8, 31, 22};
  int length = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, length);

  for (int i = 0; i < length; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}