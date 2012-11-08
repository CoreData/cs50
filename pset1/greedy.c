#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int change = 0;
    
    printf("Change: ");
    change = GetInt();
    
    printf("Change: $%d\n", change);
    return 0;
}