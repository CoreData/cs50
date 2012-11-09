#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	// Declare and intialize variables
	int pyramid_height = 0;
	
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
		The outer loop handles the count of rows to print.
		The inner loops are responsible for printing the correct number of 
		spaces and hashes. The first of the two inner loop handles spaces
        It takes the value of the loop counter form the outer loop
		plus 2 as border value since we starting the pyramid with 2 blocks;
	*/ 
	for(int i = 0; i < pyramid_height; i++) 
	{
		// Print the required spaces
        for(int j = 0; j < pyramid_height-i-1; j++)
        {
            printf("%s", " ");
        }
        // Print the '#' character.
		for(int k = 0; k < i+2; k++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}