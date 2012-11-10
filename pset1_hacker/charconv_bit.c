#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("Enter any lowercase letter: ");
    char c = GetChar();
    printf("%c\n", (c ^ (1UL << 5)));
    return 0;
}