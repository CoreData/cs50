#include <stdio.h>
#include <math.h>
#include "cs50.h"

int main(void)
{
	printf("How many apples do you have? ");
	int i = GetInt();
	printf("Mwahaha. I'm going to ear one of them!\n");
	i -= 1;
	printf("Now you have %d apples!\n", i);

	return 0;
}
