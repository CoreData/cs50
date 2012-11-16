#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * dictfile = fopen("all", "r");
	char * line = NULL;
	size_t len = 0;
    ssize_t read;

    if(argc != 2)
    {
    	printf("Please check your input. We expect a search term.\n");
    	return 1;
    }
	if(dictfile == 0)
	{
		return 2;
	}

	while ((read = getline(&line, &len, dictfile)) != -1) 
	{
		line[strlen(line)-1] = '\0';
		if(strcmp(line, argv[1]) == 0)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No.\n");
	return 0;
}