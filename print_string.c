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

int _digits(int num)
{
	int count;

	count = 0;
	if (num < 0)
		count++;
	if (num == 0)
		return (1);

	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

int print_int(int num, int (*digits)(int))
{
	digits() = &_digits;
	int i, d = 1;
	int p_int = 0;

	if (num < 0)
	{
		p_int += print_char('-');
		num = -num;
	}

	for (i = 0; i < digits)
