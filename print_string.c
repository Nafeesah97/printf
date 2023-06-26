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
