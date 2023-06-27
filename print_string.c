#include "main.h"
#include <unistd.h>

/**
 * print_char - Function that print a character
 * @c: Character to be printed
 * Return: Nothing
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Function that prints a string
 * @s: String to be printed
 * Return: Length
 */


int print_string(char *s)
{
	int i, length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	s -= length;

	for (i = 0; i < length; i++)
	{
		print_char(s[i]);
	}

	return (length);
}

/**
 * _digits - Function to count number of digits
 * @num: number to be counted
 * Return: Count
 */

int _digits(int num)
{
	int count;

	count = 0;
	if (num < 0)
		num = -num;
	if (num == 0)
		return (1);

	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
/**
 * print_int - Function to print integer
 * @num: integer to be printed
 * @digits: digits to be printed
 * Return: Printed integer
 */

int print_int(int num, int digits)
{
	int i, d = 1;
	int p_int = 0;

	if (num == 0)
	{
		p_int += print_char('0');
		return (p_int);
	}

	if (num < 0)
	{
		p_int += print_char('-');
		num = -num;
	}

	for (i = 1; i < digits; i++)
		d *= 10;

	while (d != 0)
	{
		int digit = num / d;

		p_int += print_char('0' + digit);
		num %= d;
		d /= 10;
	}
	return (p_int);
}
