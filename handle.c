#include "main.h"
#include <stdint.h>

/**
 * handle_flags - handle flags for a conversion specifier
 * @format: pointer to the format string
 * @args: argument list
 * @count: number of characters printed
 * Return: count
 */
int handle_flags(const char *format, va_list args, int count)
{
	int num;
	unsigned int oct, hex;

	if (*format == '+' || *format == ' ')
	{
		format++;
		num = va_arg(args, int);
		if (num >= 0)
		{
			_putchar(*format == '+' ? '+' : ' ');
			count++;
		}
		count += print_int(num);
	}
	else if (*format == '#')
	{
		format++;
		if (*format == 'o')
		{
			oct = va_arg(args, unsigned int);
			count += write(1, "0", 1);
			count += print_octal(oct);
		}
		else if (*format == 'x' || *format == 'X')
		{
			hex = va_arg(args, unsigned int);
			count += write(1, *format == 'x' ? "0x" : "0X", 2);
			count += *format == 'x' ? print_hex_lower(hex) : print_hex_upper(hex);
		}
	}
	return (count);
}

/**
 * handle_len_mod - handle length modifiers for conversion specifiers
 * @len_mod: length modifier character ('l' or 'h')
 * @format: format string
 * @args: argument list
 * @count: number of characters printed
 * Return: count
 */
int handle_len_mod(char len_mod, const char *format, va_list args, int count)
{
	if (*format++ == 'd' || *format++ == 'i')
	{
		if (len_mod == 'l')
			count += print_int(va_arg(args, long int));
		else if (len_mod == 'h')
			count += print_int(va_arg(args, int));
	}
	else if (*format++ == 'u')
	{
		if (len_mod == 'l')
			count += print_unsigned_int(va_arg(args, unsigned long int));
		else if (len_mod == 'h')
			count += print_unsigned_int(va_arg(args, unsigned int));
	}
	else if (*format++ == 'o')
	{
		if (len_mod == 'l')
			count += print_octal(va_arg(args, unsigned long int));
		else if (len_mod == 'h')
			count += print_octal(va_arg(args, unsigned int));
	}
	else if (*format++ == 'x')
	{
		if (len_mod == 'l')
			count += print_hex_lower(va_arg(args, unsigned long int));
		else if (len_mod == 'h')
			count += print_hex_lower(va_arg(args, unsigned int));
	}
	else if (*format++ == 'X')
	{
		if (len_mod == 'l')
			count += print_hex_upper(va_arg(args, unsigned long int));
		else if (len_mod == 'h')
			count += print_hex_upper(va_arg(args, unsigned int));
	}
	else
		count += not_ld(len_mod, format++);
	return (count);
}

/**
 * handle_width - add spaces in front of characters
 * @format: current character of format string
 * @args: list of variable arguments
 * @count: number of characters printed
 * Return: count
 */
int handle_width(const char *format, va_list args, int count)
{
	int width = 0, num, diff;
	unsigned int dig;

	while (_isdigit(*format))
		width = width * 10 + (*format++ - '0');
	if (*format == 'd' || *format == 'i')
	{
		num = va_arg(args, int);
		diff = width - get_length_int(num);
		while (diff-- > 1)
		{
			_putchar(' ');
			count++;
		}
		count += print_int(num);
	}
	else if (*format == 'o' || *format == 'u' || *format == 'x' || *format == 'X')
	{
		dig = va_arg(args, unsigned int);
		diff = width - get_length_un(dig);
		while (diff-- > 1)
		{
			_putchar(' ');
			count++;
		}
		if (*format == 'u')
			count += print_unsigned_int(dig);
		else if (*format == 'o')
			count += print_octal(dig);
		else if (*format == 'X')
			count += print_hex_upper(dig);
		else if (*format == 'x')
			count += print_hex_lower(dig);
	}
	return (count);
}
/**
 * handle_precision - handles precision for conversion specifiers
 * @format: pointer to the format string
 * @args: argument list
 * @count: number of characters printed
 * Return: count
 */
int handle_precision(const char *format, va_list args, int count)
{
	int precision = 0;
	double num;
	char *str;

	format++;
	while (_isdigit(*format))
	{
		precision = precision * 10 + (*format - '0');
		format++;
	}
	if (*format == 'f' || *format == 'e' || *format == 'g')
	{
		num = va_arg(args, double);
		count += print_float(num, precision);
	}
	else if (*format == 's')
	{
		str = va_arg(args, char *);
		count += print_string_with_precision(str, precision);
	}
	return (count);
}
/**
 * _isflag - checks if character encountered is a flag
 * @format: pointer to the format string
 * Return: count
 */
int _isflag(const char *format)
{
	return (*format == '#' || *format == '+' ||
			*format == '-' || *format == ' ' || *format == '0');
}
