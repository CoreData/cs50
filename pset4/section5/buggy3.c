#include <stdio.h>

int main(int argc, char* argv[])
{
    char* filename = "nonexistent.txt";

    FILE* file = fopen(filename, "r");

    char buffer[128];
    for (int line = 0; fgets(buffer, sizeof(buffer), file) != NULL; line++)
    {
        printf("%d: %s", line, buffer);
    }

    fclose(file);

    return 0;
}
