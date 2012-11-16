#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE
#define SALT_LENGTH 2

int permutate(char[2], char*);
int inc(char *);
bool done = false;

int main(int argc, string argv[])
{
	char salt[2];
	char * password;
	char * force;
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

	// wordfile = fopen("/usr/share/dict/words", "r");
    // wordfile = fopen("D8.DIC", "r");
    // wordfile = fopen("Jargon", "r");
    // wordfile = fopen("dic-0294.txt", "r");
    // wordfile = fopen("NORM&R.DIC", "r");
    // wordfile = fopen("common-passwords.txt", "r");
    wordfile = fopen("all", "r");

    if (wordfile == NULL)
    {
    	return 2;
    }

    while(!done)
    {
	    while ((read = getline(&line, &len, wordfile)) != -1) 
	    {
	    	line[strlen(line) - 1] = 0;
	    	printf("Currently @ %s\n", line);
	    	test = crypt(line, salt);
	        if(strcmp(argv[1], test) == 0)
	        {
	        	printf("%s\n", line);
	        	done = true;
	        	return 0;
	        	
	        }
	    }

	    if (line)
	    {
			free(line);
		}
		force = argv[1];
	    permutate(salt, force);
	}

	printf("\n");
    return 0;
}

int permutate(char salt[2], char *force)
{
    int n = 8;
    char * test;
    char * temp;

    char *c = malloc((n+1)*sizeof(char));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0;j < i; j++)
        {
            c[j]='!';
        }
        c[i]=0;
        do 
        {
        	// printf("Currently @ %s\n", c);
        	test = crypt(c, salt);
            if(strcmp(force, test) == 0)
            {
            	printf("%s", c);
            	done = true;
            	return 0;
            }
        } while(inc(c));
    }
    free(c);
    return 0;
}

int inc(char *c)
{
    if(c[0]==0) 
    {
        return 0;
    }

    if(c[0]=='~')
    {
        c[0]='!';
        return inc( c + sizeof(char));
    }   
    c[0]++;
    return 1;
}
