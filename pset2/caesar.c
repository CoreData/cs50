/*
    Author: Chris Anders, chris@hell-labs.de
    
    This file presents a solution to pset2 of CS50x.
*/
        
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    bool keySuccessful = false;
    int key = 0;
    int input_length = 0;
    // string text = "Be sure to drink your Ovaltine!";
    string text = "";
    
    do
    {
        if(argc != 2)
        {
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            keySuccessful = true;
        }
    } while(!keySuccessful);
    
    text = GetString();
    input_length = strlen(text);
    for(int i = 0; i < input_length; i++)
    {
        if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                printf("%c", ((((text[i] - 97)+key)%26)+97));
            }
            else if(isupper(text[i]))
            {
                printf("%c", ((((text[i] - 65)+key)%26)+65));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;  
}