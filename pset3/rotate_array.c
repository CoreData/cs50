#include <stdio.h>

#define SIZE 4

int main(void)
{
	int value = 0;
	int first_array[SIZE][SIZE];
	int second_array[SIZE][SIZE];

	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col < SIZE; col++)
		{
			value = col + SIZE*row + 1;
			first_array[row][col] = value;
		}
	}

	printf("\n");

	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col <SIZE; col++)
		{
			printf("%i ", first_array[row][col]);
		}
		printf("\n");
	}

	printf("\n90 Degrees CCW:\n\n");

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = (SIZE-1); j >=0; j--)
		{
			second_array[i][(SIZE-1)-j] = first_array[j][i];
		}
	}

	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col <SIZE; col++)
		{
			printf("%i ", second_array[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}