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
	int convert = 0, count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			convert += handle_conversion(format, args);
			if (convert == -1)
				return (-1);
			count += convert;
			if (_isflag(format))
			{
				format++;
				if (_isdigit(*format))
				{
					count += handle_width(format, args, count);
					format++;
				}
			}
			else if ((_isdigit(*format) && *format != 0) || is_len_mod(format))
				format++;
			else if (*format == '.' && _isdigit(*(format + 2)))
				format++;
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
