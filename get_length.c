#include "main.h"

/**
 * get_length_int - finds lenghth of an integer
 * @num: integer value
 * Return: Length
 */
int get_length_int(int num)
{
	int length = 0;

	if (num < 0)
	{
		length++;
		num = -num;
	}
	if (num == 0)
		length = 1;
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

/**
 * get_length_float - finds the length of a float
 * @num: float value
 * Return: length
 */
int get_length_float(double num)
{
	int length = 0;
	int int_part;
	double decimal_part;

	if (num < 0)
	{
		length++;
		num = -num;
	}
	/*extract the integer part*/
	int_part = (int)num;
	length += get_length_int(int_part);

	/*Extract the decimal part*/
	decimal_part = num - int_part;
	if (decimal_part > EPSILON)
	{
		length++;
		while (decimal_part > EPSILON)
		{
			decimal_part *= 10;
			length++;
			decimal_part -= (int)decimal_part;
		}
	}
	return (length);
}

/**
 * get_length_unsigned - gives the length of unsigned integers
 * @num: unsigned integer
 * Return: length
 */
int get_length_un(unsigned int num)
{
	int length = 0;

	if (num == 0)
		length = 1;
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

/**
 * _strlen - finds length of a string
 * @str: string value
 * Return: length
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

