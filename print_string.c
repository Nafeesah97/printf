#include "main.h"
#include <unisted.h>

int print_string(char *s)
{
	int i, length;

	length = 1;
	while (s != '\0')
	{
		length++;
		s++;
	}

	for (i = 0; i < length; i++)
	{
		print_char(s[i]);
	}
	return (0);
}
