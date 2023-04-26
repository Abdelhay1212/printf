#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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

/**
 * _printf - prints strings characters and numbers
 * @format: string to be printed
 * Return: integer
 **/
int _printf(const char *format, ...)
{
	int i = 0, count = 0, integer;
	unsigned int hex;
	char *str, *ptr, c;
	va_list args;

	if (format == NULL)
		return (-1);

	ptr = malloc(20 * sizeof(char));
	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			count++;
			i++;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					c = va_arg(args, int);
					if (c != '\0')
						putchar(c);
					else
						putchar(' ');
					count++;
					break;
				case 's':
					str = va_arg(args, char*);
					if (str == NULL)
						str = "(null)";
					for (; *str; str++)
					{
						putchar(*str);
						count++;
					}
					break;
				case 'd':
				case 'i':
					integer = va_arg(args, int);
					if (integer == '\0')
					{
						putchar('0');
						count++;
					}
					else
					{
						sprintf(ptr, "%d", integer);
						for (; *ptr; ptr++)
						{
							putchar(*ptr);
							count++;
						}
					}
					break;
				case 'x':
				case 'X':
					c = format[i + 1];
					hex = va_arg(args, unsigned int);
					count = print_hex(hex, count, c);
					break;
				default:
					putchar(format[i]);
					count++;
					i--;
					break;
			}
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
