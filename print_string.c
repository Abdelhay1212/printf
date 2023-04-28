#include <stdio.h>

/**
  * print_string - print strings
  * @str: pointer to string
  * @count: integer
  * Return: integer
  **/

int print_string(char *str, int count)
{
	if (str == NULL)
		str = "(null)";
	for (; *str; str++)
	{
		putchar(*str);
		count++;
	}
	return (count);
}

