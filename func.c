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
	char dig_char, neg, buffer[BUF_SIZE];

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	if (num < 0)
	{
		neg = '-';
		count++;
		num = -num;
	}
	while (num != 0)
	{
		digit = num % 10;
		dig_char = ('0' + digit);
		buffer[index++] = dig_char;
		count++;
		num /= 10;
	}
	reverse_string(buffer, index);
	if (neg == '-')
	{
		_putchar('-');
		write(1, buffer, index);
	}
	else
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
