#include "main.h"
/**
 * print_float - prints floating point integers with precison
 * @num: number
 * @precision: precision which must be greater than 0
 * Return: count
 */
int print_float(double num, int precision)
{
	int digit, integer_part = (int)num;
	double decimal_part = num - integer_part;
	int count = print_int(integer_part);

	if (precision > 0)
	{
		_putchar('.');
		count++;
		while (precision > 0)
		{
			decimal_part *= 10;
			digit = (int)decimal_part;
			_putchar('0' + digit);
			decimal_part -= digit;
			precision--;
			count++;
		}
	}
	return (count);
}
/**
 * print_string_with_precision - handles precison for strings
 * @str: string
 * @precision: precision which must be greater than 0
 * Return: count
 */
int print_string_with_precision(char *str, int precision)
{
	int count = 0, c, len;

	if (precision < 0)
		count = write(1, str, _strlen(str));
	else
	{
		len = _strlen(str);
		c = (precision < len) ? precision : len;
		count = write(1, str, c);
	}
	return (count);
}
/**
 * _isalpha - checks for alphabet
 * @c: character to check
 * Return: 1 is True, otherwise 0
 */
int _isalpha(int c)
{
	return (_islower(c) || (c >= 'A' && c <= 'Z'));
}
