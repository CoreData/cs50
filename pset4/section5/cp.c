#define LINE_LENGTH 512

#include <stdio.h>


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source destination\n");
        return 1;
    }

    FILE* sfile = fopen(argv[1], "r");
    FILE* dfile = fopen(argv[2], "w");

    if(sfile == NULL) 
    {
    	perror(argv[1]);
    	return 1;
    }
    if(dfile == NULL)
    {
    	perror(argv[2]);
    	return 2;
    }

    // We should handle this in a dynamic fashion. 
    // Using fgets with a static char array we will f*ck up 
    // when we have a really long line.
    char line[LINE_LENGTH];

    while(fgets(line, LINE_LENGTH, sfile) != NULL)
    {
    	fprintf(dfile, "%s", line);
    }

    fclose(sfile);
    fclose(dfile);

    return 0;
}

