#include "main.h"
/**
 * print_strings - for format specifier s
 * @str: string
 * Return: number of characters printed
 */
int print_strings(char *str)
{
	int i, count = 0;
	char buffer[BUF_SIZE];

	if (str == NULL)
		write(1, "(null)", 6);
	while (str[count] != '\0' && count < BUF_SIZE)
		count++;
	for (i = 0; i < count; i++)
		buffer[i] = str[i];
	buffer[i] = '\0';
	return (write(1, buffer, count));
}
/**
 * print_percent - print percent
 * Return: 1
 */
int print_percent(void)
{
	int count = 0;

	write(1, "%%", 1);
	count++;
	return (count);
}
/**
 * print_char - handle format specifer c
 * @c: character
 * Return: 1 for single charater printed
 */
int print_char(char c)
{	int count = 0;

	write(1, &c, 1);
	count++;
	return (count);
}
/**
 * print_nonprintable - handles format specifer S
 * @str: string of characters
 * Return: count
 */
int print_nonprintable(char *str)
{
	int len = 0, count, i;

	if (str == NULL)
		write(1, "(null)", 6);
	while (str[len])
		len++;
	for (i = 0; i < len; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += write(1, "\\x", 2);
			count += print_hex((unsigned int)(unsigned char)str[i]);
		}
		else
			count += write(1, &str[i], 1);
	}
	return (count);
}
/**
 * print_pointer - handle format specifier p
 * @ptr: pointer to variable of any data type
 * Return: 2
 */
int print_pointer(void *ptr)
{
	uintptr_t ptr_value = (uintptr_t)ptr;
	int count = 0;

	count += write(1, "0x", 2);
	count += print_hex_lower((unsigned int)ptr_value);
	return (count);
}
