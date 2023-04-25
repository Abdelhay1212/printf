#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints strings characters and numbers
 * @format: string to be printed
 * Return: integer
 **/
int _printf(const char *format, ...)
{
	int i;
	char *str, *c;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	i = 0;

	while (format[i])
	{
		if (format[i] != '%')
			putchar(format[i]);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			i++;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					c = va_arg(args, char*);
					if (*c != NULL)
						putchar(format[i]);
					else
						putchar(' ');
					break;
				case 's':
					str = va_arg(args, char*);
					if (str == NULL)
						str = "(null)";
					for (; *str; str++)
						putchar(*str);
					break;
				default:
					putchar(format[i]);
					i--;
					break;
			}
			i++;
		}
		i++;
	}
	va_end(args);
	return (i);
}
