#include <stdio.h>

/**
  * print_hex - print hexadecimal numbers
  * @n: hexadicimal
  * @count: length of decimals
  * @charType: character
  * Return: integer
  */
int print_hex(unsigned int n, int count, char charType)
{
	if (n >= 16)
	{
		count = print_hex(n / 16, count, charType);
	}

	int digit = n % 16;

	if (digit < 10)
	{
		putchar('0' + digit);
		count++;
	}
	else
	{
		if (charType == 'x')
			putchar('a' + digit - 10);
		else
			putchar('A' + digit - 10);
		count++;
	}
	return (count);
}
