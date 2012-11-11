#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    // Variable declarations
    bool keySuccessful = false;
    string keyword = "";
    int keylength = 0;
    string keyword_upper = "";
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
    
    return 0;
}