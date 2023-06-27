#include "main.h"

int print_int(int num);
void reverse_string(char *str, int length);
/**
 * _putchar - prints characters
 * @c: character
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - print integers
 * @num: number
 * Return: count
 */
int print_int(int num)
{
	int index = 0, count = 0, digit;
	char buffer[BUF_SIZE], dig_char;
	bool is_negative = false;

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	if (num < 0)
	{
		num = -num;
		is_negative = true;
	}
	while (num != 0)
	{
		digit = num % 10;
		dig_char = digit + '0';
		buffer[index++] = dig_char;
		count++;
		num /= 10;
	}
	if (is_negative)
	{
		buffer[index++] = '-';
		count++;
	}
	buffer[index] = '\0';
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}

/**
 * reverse_string - functions reverses rhe order of characters in given string
 * @str: function parameter providing strings
 * @length: length of the string
 */
void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 * print_hex - prints hexadecimal that is 2 chars long
 * @num: unsigned integer
 * Return: count
 */
int print_hex(unsigned int num)
{
	int count = 0, index = 0, digit;
	char buffer[BUF_SIZE], dig_char;

	while (num != 0)
	{
		digit = num % 16;
		dig_char = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
		buffer[index++] = dig_char;
		count++;
		num /= 16;
	}
	if (count < 2)
		buffer[index++] = '0';
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}
