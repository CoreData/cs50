#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int x, y = 0;

	printf("x: ");
	x = GetInt();
	printf("y: ");
	y = GetInt();

	printf("x is %d\ny is %d\n", x,y);

	x = x + y;
	y = x - y;
	x = x - y;

	printf("x is %d\ny is %d\n", x,y);

	return 0;
}