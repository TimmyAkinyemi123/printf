#include "main.h"
/**
 * handle_conversion - handles conversion specifers, modifiers and flags
 * @format: format string
 * @args: the argument list
 * Return: characters printed
 */
int handle_conversion(const char *format, va_list args)
{
	int count = 0;

	if (*format == 'c')
		count += print_char(va_arg(args, int));
	else if (*format == 's')
		count += print_strings(va_arg(args, char*));
	else if (*format == 'S')
		count += print_nonprintable(va_arg(args, char*));
	else if (*format == 'd' || *format == 'i')
		count += print_int(va_arg(args, int));
	else if (*format == 'u')
		count += print_unsigned_int(va_arg(args, unsigned int));
	else if (*format == 'o')
		count += print_octal(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += print_hex_lower(va_arg(args, unsigned int));
	else if (*format == 'X')
		count += print_hex_upper(va_arg(args, unsigned int));
	else if (*format == 'b')
		count += print_bin(va_arg(args, unsigned int));
	else if (*format == 'p')
		count += print_pointer(args);
	else if (*format == 'r')
		count += print_reversed_string(va_arg(args, char*));
	else if (*format == 'R')
		count += print_rot13_string(va_arg(args, char*));
	else if (*format == 'l' || *format == 'h' || _isdigit(*format))
		count = (*format == '.' ? handle_precision(format, args, count) :
				handle_len_mod(*format, format, args, count));
	else if (_isflag(format))
		count += handle_flags(format, args, count);
	else
		return (0);
	return (count);
}
/**
 * not_ld - else option when not length modifier
 * @len_mod: length modifier
 * @format: format string
 * Return: count
 */
int not_ld(char len_mod, const char *format)
{
	int count = 0;

	_putchar('%');
	_putchar(len_mod);
	_putchar(*format);
	count += 3;

	return (count);
}
/**
 * print_reversed_string - prints string in reverse
 * @str: string
 * Return: number of characters printed
 */
int print_reversed_string(char *str)
{
	int count = 0, i;
	char buffer[BUF_SIZE];

	if (str == NULL)
		write(1, "(null)", 6);
	while (str[count] != '\0')
		count++;
	for (i = 0; i < count; i++)
		buffer[i] = str[i];
	buffer[i] = '\0';
	reverse_string(buffer, count);

	return (write(1, buffer, count));
}
/**
 * print_rot13_string - prints string in rotated 13
 * @str: string
 * Return: number of characters printed
 */
int print_rot13_string(char *str)
{
	int count = 0;
	char base, rot;

	while (*str)
	{
		if (_isalpha(*str))
		{
			base = _islower(*str) ? 'a' : 'A';
			rot = ((*str - base) + 13) % 26 + base;
			_putchar(rot);
			count++;
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}
	return (count);
}
/**
 * _islower - checks for lowercase alphabets
 * @c: character
 * Return: 1 if True, otherwise 0
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
