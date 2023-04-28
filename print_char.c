/**
  * print_char - prints characters
  * @c: character
  * @count: integer
  * Return: integer
  **/

int print_char(char c, int count)
{
	if (c != '\0')
		putchar(c);
	else
		putchar(' ');
	count++;
	return (count);
}
