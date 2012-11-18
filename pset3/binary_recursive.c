#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int min, int size)
{
	int max = size;
	if(size < min)
	{
		return false;
	}
	else
	{
		int mid = max/2;

		if(haystack[mid] > needle)
		{
			return search(needle, haystack, min, mid - 1);
		}
		else if(haystack[mid] < needle)
		{
			return search(needle, haystack, mid+1, max);
		}
		else
		{
			return true;
		}

	}
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, 0, SIZE))
        printf("YES\n");
    return 0;
}