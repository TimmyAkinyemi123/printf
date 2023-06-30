#include "main.h"

/**
 * print_unsigned_int - print unsigned integers
 * @num: unsigned integer
 * Return: count
 */
int print_unsigned_int(unsigned int num)
{
	int index = 0, count = 0, digit;
	char buffer[BUF_SIZE], dig_char;

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	while (num != 0)
	{
		digit = num % 10;
		dig_char = '0' + digit;
		buffer[index++] = dig_char;
		count++;
		num /= 10;
	}
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}
/**
 * print_bin - print numbers in binary form
 * @num: unsigned integer
 * Return: count
 */
int print_bin(unsigned int num)
{
	int count = 0, index = 0;
	unsigned int mask;
	char buffer[BUF_SIZE];

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	mask = 1u << (sizeof(unsigned int) * 8 - 1);

	while ((mask & num) == 0 && mask > 1)
		mask >>= 1;
	while (mask > 0)
	{
		if (num & mask)
			buffer[index++] = '1';
		else
			buffer[index++] = '0';
		count++;
		mask >>= 1;
	}
	buffer[index] = '\0';
	write(1, buffer, index);
	return (count);
}
/**
 * print_octal - print numbers in base 8
 * @num: unsigned integer
 * Return: count
 */
int print_octal(unsigned int num)
{
	int index = 0, count = 0, digit;
	char buffer[BUF_SIZE], dig_char;

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	while (num != 0)
	{
		digit = num % 8;
		dig_char = '0' + digit;
		buffer[index++] = dig_char;
		count++;
		num /= 8;
	}
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}
/**
 * print_hex_lower - prints lowercase hexadecimal digits
 * @num: unsigned integer
 * Return: count
 */
int print_hex_lower(unsigned long num)
{
	int count = 0, index = 0, digit;
	char buffer[BUF_SIZE], dig_char;

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	while (num != 0)
	{
		digit = num % 16;
		dig_char = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		buffer[index++] = dig_char;
		count++;
		num /= 16;
	}
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}
/**
 * print_hex_upper - prints uppercase hexadecimal digits
 * @num: unsigned integer
 * Return: count
 */
int print_hex_upper(unsigned int num)
{
	int count = 0, index = 0, digit;
	char buffer[BUF_SIZE], dig_char;

	if (num == 0)
	{
		buffer[index++] = '0';
		write(1, buffer, index);
		return (1);
	}
	while (num != 0)
	{
		digit = num % 16;
		dig_char = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
		buffer[index++] = dig_char;
		count++;
		num /= 16;
	}
	reverse_string(buffer, index);
	write(1, buffer, index);
	return (count);
}
