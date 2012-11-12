/*
    Author: Chris Anders, chris@hell-labs.de
    
    This file presents a solution for the caesar problem in pset2 of CS50x.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    // Variable declarations
    bool keySuccessful = false;
    int key = 0;
    int input_length = 0;
    string text = "";
    
    // Get input
    do
    {
        // The number of command line args submitted was incorrect. 
        if(argc != 2)
        {
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            printf("We require an integer as encryption key.\n");
            return 1;
        }
        else
        {
            // Key needs to be converted from string to int
            key = atoi(argv[1]);
            keySuccessful = true;
        }
    } while(!keySuccessful);
    
    // Read user input
    text = GetString();
    input_length = strlen(text);
    for(int i = 0; i < input_length; i++)
    {
        // Process characters
        if(isalpha(text[i]))
        {
            // Work with lower case characters
            if(islower(text[i]))
            {
                printf("%c", ((((text[i] - 97)+key)%26)+97));
            }
            // Work with upper case characters
            else
            {
                printf("%c", ((((text[i] - 65)+key)%26)+65));
            }
        }
        // "Mirror" all other input to the result string w/out processing
        else
        {
            printf("%c", text[i]);
        }
    }
    // Be a good citizen and exit cleanly. 
    printf("\n");
    return 0;  
}