#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	// Declare and intialize variables
	int pyramid_height = 0;
	int i = 0;
	int j = 0;
    int k = 0;
	
	// Grab user input, check it and ask for retry if not within bounds  
	do {
		printf("Height:");
		pyramid_height = GetInt();
        if (pyramid_height == 0)
        {
            return 0;
        }
	} while (pyramid_height < 1 || pyramid_height > 23);

	/*
		The outer loop handles the count of rows to print as well as the
		count of spaces to be printed in front of the hashes.
		The inner loop is responsible for printing the correct number of 
		hashes. It takes the value of the loop counter form the outer loop
		plus 2 as border value since we starting the pyramid with 2 blocks;
	*/ 
	for(i = 0; i < pyramid_height; i++) 
	{
		// Print the required spaces
        for(k = 0; k < pyramid_height-i-1; k++)
        {
            printf("%s", " ");
        }
        // Print the '#' character.
		for(j = 0; j < i+2; j++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}