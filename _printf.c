#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * ... : The values to format and print
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
{
	if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'
	|| format[i + 1] == '%'
	|| format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == 'b'))
	{
		switch (format[i + 1])
		{
			case 'c';
			print_char(args);
			break;
			case 's':
			print_string(args);
			break;
			case '%':
			print_percent();
			break;
			case 'd':
			case 'i':
			print_integer(args);
			break;
			case 'b':
			print_binary(args);
			break;
		}
		i++;
	}
	else
	{
		write(1, &format[i], 1);
	}
	i++;
	}
	va_end(args);
	return (i);
}

