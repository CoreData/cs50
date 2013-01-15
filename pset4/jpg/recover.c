/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(void)
{
	// Open the cardfile, return if there's a problem with it
	FILE* fp = fopen("card.raw", "r");	

	if(fp == NULL)
	{	
		fclose(fp);
		fprintf(stderr, "Wasn't able to open the cardfile.\n");
		return 1;
	}
	
	// These are the starting bytes of a jpeg file.
	uint8_t checkjpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
	uint8_t checkjpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
	int jpgcount = 0;

	while(feof(fp) == 0)
	{
		// Read 512b blocks from file.
		uint8_t buffer[512];
		uint8_t check[3];
		fread(buffer, 512, 1, fp);	
		
		for(int i = 0; i < 4; i++)
		{
			check[i] = buffer[i];
		}

		if(memcmp(checkjpg1, check, sizeof(checkjpg1) == 0) || (memcmp(checkjpg2, check, sizeof(checkjpg2)) == 0))
		{
		  jpgcount++;
		}
	}


	printf("%d jpeg files found.\n", jpgcount);

	// Close cardfile, be a good citizen and exit.
	fclose(fp);
	return 0;
}
