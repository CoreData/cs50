#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char token, int key);

int main(int argc, string argv[]) {

    // Variable declarations
    bool keySuccessful = false;
    string keyword = "";
    int keylength = 0;
    string keyword_upper = "";
    string cipher_text = "";
    int cipher_length;
    int key_count = 0;

    do
    {
        // The number of command line args submitted was incorrect. 
        if(argc != 2)
        {
            printf("You didn't enter the correct number of keywords.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    printf("Your input contains illegal characters.\n");
                    return 1;
                }
                else
                {
                    keySuccessful = true;
                    keyword = argv[1];
                }
            }
        }
    } while(!keySuccessful);
    
    keylength = strlen(keyword);
    int keycodes[keylength];
    
    for(int i = 0; i < keylength;i++)
    {
        keycodes[i] = toupper(keyword[i]) - 65;
        printf("%d ", keycodes[i]);
    }
        
    printf("\n%s\n", keyword);
    printf("%d\n", keylength);

    cipher_text = GetString();
    // printf("Your cipher: %s\n", cipher_text);
    cipher_length = strlen(cipher_text);

    for (int i = 0; i < cipher_length; i++)
    {
        if(!isalpha(cipher_text[i]))
        {
            printf("%c", cipher_text[i]);
        }
        else
        {
            printf("%c", caesar(cipher_text[i], keycodes[key_count]));

            if(key_count < keylength)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }

    printf("\n");
    return 0;
}

char caesar(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 97)+key)%26)+97);
    }
    else
    {
        return ((((token - 65)  +key)%26)+65);
    }
}