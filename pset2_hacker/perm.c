#include <stdlib.h>
#include <stdio.h>

int inc(char *);

int main(void)
{
    int n = 8;
    char *c = malloc((n+1)*sizeof(char));
    FILE * wordfile = fopen("/Volumes/Home/chrisanders/text.txt", "w");
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0;j < i; j++)
        {
            c[j]='!';
        }
        c[i]=0;
        do 
        {
            if(wordfile)
            {
                fprintf(wordfile, "%s\n", c);
            }
        } while(inc(c));
    }
    free(c);
    return 0;
}

int inc(char *c)
{
    if(c[0]==0) 
    {
        return 0;
    }

    if(c[0]=='~')
    {
        c[0]='!';
        return inc( c + sizeof(char));
    }   
    c[0]++;
    return 1;
}