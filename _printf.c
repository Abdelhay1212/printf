#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints strings characters and numbers
 * @format: string to be printed
 * Return: integer
 **/
int _printf(const char *format, ...)
{
	int i = 0, count = 0, integer;
	unsigned int hex;
	char *str, c;
	va_list args;

	if (format == NULL)
		return (-1);

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
					count = print_char(c, count);
					break;
				case 's':
					str = va_arg(args, char*);
					count = print_string(str, count);
					break;
				case 'd':
				case 'i':
					integer = va_arg(args, int);
					count = print_integer(integer, count);
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
