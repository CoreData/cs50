#include <stdio.h>
#include <string.h>

int main(void)
{
	char * first = "Hallo";
	char * second = "Halle";

	printf("First String: %s\n", first);
	printf("Second String: %s\n", second);

	printf("%d\n", strcmp(first, second));

	return 0;
}