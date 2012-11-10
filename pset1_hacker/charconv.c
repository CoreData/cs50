#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("Enter any lowercase letter: ");
    char c = GetChar();
    printf("%c\n", c-32);
    return 0;
}