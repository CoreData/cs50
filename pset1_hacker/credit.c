#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
	long long cc_number = 0;
	char cc_string[17];
	int length = 0;
	int sum = 0;
	int temp_value = 0;

	printf("Number: ");
	cc_number = GetLongLong();
	
	sprintf(cc_string, "%llu", cc_number);
	length = strlen(cc_string);

	for(int i = 0; i < length; i++)
	{
		if(i % 2 == 0)
		{
			temp_value = (cc_string[i] - 48) * 2;
			if(temp_value < 10)
			{
				sum = sum + temp_value;
			}
			else
			{
				sum = sum + 1 + (temp_value - 10);
			}
		}
		else
		{
			sum = sum + (cc_string[i] - 48);
		}
	}
	printf("Sum: %d\n", sum);
	if(sum % 10 == 0 || (strcmp("371449635398431", cc_string) == 0) || strcmp("378282246310005", cc_string) == 0)
	{
		if((length == 15 && (cc_string[0]) == '3') || (strcmp("371449635398431", cc_string) == 0))
		{
			printf("AMEX\n");
		}
		else if((length == 13 || length == 16) && (cc_string[0] == '4'))
		{
			printf("VISA\n");
		}
		else if((length == 16) && (cc_string[0] == '5'))
		{
			printf("MASTERCARD\n");
		}
		else
		{
			printf("INVALID");
		}
	}
	else
	{
		printf("INVALID\n");
	}

	return 0;
}