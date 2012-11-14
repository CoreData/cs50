#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

// #define _XOPEN_SOURCE
#define SALT_LENGTH 2

int main(int argc, string argv[])
{
	int argument_length = 0;
	char salt[2];
	char * password;
	char * test;
	FILE * wordfile;
	char * line = NULL;
	size_t len = 0;
    ssize_t read;

	if(argc != 2)
	{
		printf("Wrong number of command line arguments.\nPlease enter an encrypted password.\n");
		return 1;
	}

	// First two characters are salt, all following input is encrypted password.
	strncpy(salt, argv[1], SALT_LENGTH);
	password = argv[1] + 2;

	wordfile = fopen("/usr/share/dict/words", "r");
	// wordfile = fopen("text", "r");

    if (wordfile == NULL)
    {
    	exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, wordfile)) != -1) 
    {
    	line[strlen(line) - 1] = 0;
    	test = crypt(line, salt);
        if(strcmp(argv[1], test) == 0)
        {
        	printf("%s", line);
        	break;
        }
    }

    if (line)
    {
		free(line);
	}

	printf("\n");
    return 0;
}