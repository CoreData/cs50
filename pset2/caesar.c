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
            return -1;
        }
        else
        {
            // printf("Your valid input is here: %s\n", argv[1]);
            key = atoi(argv[1]);
            keySuccessful = true;
        }
    } while(!keySuccessful);
    
    text = GetString();
    input_length = strlen(text);
    for(int i = 0; i < input_length; i++)
    {
        if(isspace(text[i]) || isdigit(text[i]) || ispunct(text[i]))
        {
            printf("%c", text[i]);
        }
        else
        {
            if(islower(text[i]))
            {
                if(text[i] + key > 122)
                {
                    printf("%c", 97 + (key - (123 - text[i])));
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }
            else if(isupper(text[i]))
            {
                if(text[i] + key > 90)
                {
                    printf("%c", 65 + (key - (91 - text[i])));
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }
        }
    }
    printf("\n");
    return 0;  
}