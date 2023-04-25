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
	char *str;
	va_list args;
	char percente;
	char c;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	percente = '%';
	i = 0;

	while (format[i])
	{
		if (format[i] != '%')
			write(STDOUT_FILENO, &format[i], sizeof(format[i]));
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(STDOUT_FILENO, &percente, sizeof(percente));
			i++;
		}
		else
		{
			switch(format[i + 1])
			{
				case 'c':
					c = va_arg(args, int);
					write(STDOUT_FILENO, &c, sizeof(c));
					break;
				case 's':
					str = va_arg(args, char*);
					for (; *str; str++)
						write(STDOUT_FILENO, str, sizeof(*str));
					break;
			}
			i++;
		}
		i++;
	}
	va_end(args);
	return (i);
}
