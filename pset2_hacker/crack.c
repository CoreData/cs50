#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
	if(argc != 2)
	{
		printf("Wrong number of command line arguments.\nPlease enter an encrypted password.\n");
		return 1;
	}
	printf("%s", argv[1]);
	printf("\n");
	return 0;
}