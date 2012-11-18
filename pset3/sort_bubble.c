#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < i-1; j++)
    {
      if (array[j] > array[j+1])
      {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      } 
    } 
  }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}