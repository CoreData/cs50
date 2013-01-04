#include <stdlib.h>
#include <stdio.h>

void oh_no(void)
{
    char** s = NULL;
    *s = "BOOM";
    // printf("Boom\n");
}

void slinky(int i)
{
    if (i == 2)
    {
        oh_no();
    }
}

void dinky(int i)
{
    if (i == 1)
    {
        oh_no();
    }
    else
    {
        slinky(i);
    }
}

void binky(int i)
{
    if (i == 0)
    {
        oh_no();
    }
    else
    {
        dinky(i);
    }
}

int main(int argc, char* argv[])
{
    int i = rand() % 3;
    binky(i);
    return 0;
}
