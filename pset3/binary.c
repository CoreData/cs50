#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size)
{
	int min = 0;
	int max = size;

 //    if((haystack[0] == needle) || (haystack[SIZE - 1] == needle))
	// {
	// 	return true;
	// }
	
	// if(size == 0)
	// {
	// 	return false;
	// }

	while(max >= min)
	{
		int mid = (max+min)/2;

		if(haystack[mid] < needle)
		{
			min = mid + 1;
		}
		else if(haystack[mid] > needle)
		{
			max = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;
}