#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float change = 0;
    
    do 
    {
        printf("Change: ");
        change = GetFloat();
    }
    while(change <= 0);

    printf("Change: %d\n", (int)round(change*100));
    return 0;
}