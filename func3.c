#include "main.h"
/**
 * print_strings - for format specifier s
 * @str: string
 * Return: number of characters printed
 */
int print_strings(char *str)
{
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len] != '\0')
		len++;
	return (write(1, str, len));
}
/**
 * print_percent - print percent
 * Return: 1
 */
int print_percent(void)
{
	return (write(1, "%%", 1));
}
/**
 * print_char - handle format specifer c
 * @c: character
 * Return: 1 for single charater printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_nonprintable - handles format specifer S
 * @args: variable argument list
 * Return: count
 */
int print_nonprintable(va_list args)
{
	int len = 0, count, i;
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(nil)";
	while (str[len])
		len++;
	for (i = 0; i < len; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += write(1, "\\x", 2);
			count += print_hex_upper((unsigned int)str[i]);
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
	int count = write(1, "0x", 2);

	count += print_hex_lower(ptr_value);
	return (count);
}
