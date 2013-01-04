#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (strcmp("CS50 rocks", argv[1]) == 0)
    {
        printf("You get an A!\n");
    }
    else
    {
        printf("You get a D :-(\n");
    }
    return 0;
}
