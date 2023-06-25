#include "main.h"
#include <unistd.h>

int print_char(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *s)
{
	int i, length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (print_char(s[i]) < 0)
			return (-1);
	}
	return (length);
}
