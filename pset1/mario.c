#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	// Declare and intialize variables
	int pyramid_height = 0;
	int i = 0;
	int j = 0;
	
	// Grab user input, check it and ask for retry if not within bounds  
	do {
		printf("Height: ");
		pyramid_height = GetInt();
	} while (pyramid_height < 1 || pyramid_height > 24);
	
	/*
		The outer loop handles the count of rows to print as well as the
		count of spaces to be printed in front of the hashes.
		The inner loop is responsible for printing the correct number of 
		hashes. It takes the value of the loop counter form the outer loop
		plus 2 as border value since we starting the pyramid with 2 blocks;
	*/ 
	for(i = 0; i < pyramid_height; i++) 
	{
		// Print as many spaces as defined by the value of second parameter.
		printf("%*s", pyramid_height-i, " ");
		for(j = 0; j < i+2; j++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}