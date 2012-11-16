#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char * message;
    int count = 0;

    printf("Please enter a message: \n");
    message = GetString();

    for(int i = 0, length = strlen(message); i < length; i++)
    {
        if((message[i] > 'A' && message[i] < 'Z') || (message[i] > 'a' && message[i] < 'z'))
        {
            if(!(count % 2))
            {
                message[i] &= ~('a' - 'A');
            }
            else
            {
                message[i] |= ('a' - 'A'); 
            }
            count++;
        }
    }
    printf("%s\n", message);
    return 0;
}