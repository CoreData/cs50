#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    for(int i = 2; i < size; i++)
    {
        int to_sort = array[i];
        int j = i;

        while(j > 1 && array[j-1] > to_sort)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = to_sort;
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