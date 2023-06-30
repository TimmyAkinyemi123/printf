#include "main.h"

int _isdigit(char c);
int is_len_mod(const char *format);

/**
 * _printf - prints any character
 * @format: format string
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0, convert = 0;
	va_list args;

	va_start(args, format);

	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
				count += print_percent();
			convert = handle_conversion(format, args);
			if (convert == 0)
				count += _putchar(*format);
			else
				count += convert;
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * _isdigit - checks is character is digit
 * @c: function parameter
 * Return: Always 0
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_len_mod - checks string
 * @format: funtcion parameter
 * Return: Always 0
 */
int is_len_mod(const char *format)
{
	return (*format == '1' || *format == 'h');
}
