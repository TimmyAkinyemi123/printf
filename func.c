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
	int index = 0, count = 0;
	char neg, buffer[BUF_SIZE];

	if (num == 0)
	{
		buffer[index++] = '0';
		buffer[index] = '\0';
		write(1, buffer, index);
		return (1);
	}
	if (num < 0)
	{
		neg = '-';
		num = -num;
	}
	while (num != 0)
	{
		buffer[index++] = (num % 10) + '0';
		count++;
		num /= 10;
	}
	buffer[index] = '\0';
	reverse_string(buffer, index);
	if (neg == '-')
	{
		write(1, &neg, 1);
		count++;
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
