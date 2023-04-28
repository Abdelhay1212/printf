#include <stdio.h>

/**
 * print_integer - prints intgeres
 * @integer: integer to be printed
 * @count: integer
 * Return: integr
 **/
int print_integer(int integer, int count)
{
	int i;
	char str[20];

	if (integer == '\0')
	{
		putchar('0');
		count++;
	}
	else
	{
		sprintf(str, "%d", integer);
		for (i = 0; str[i] != '\0'; i++)
		{
			putchar(str[i]);
			count++;
		}
	}
	return (count);
}
