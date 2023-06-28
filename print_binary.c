#include <stdlib.h>
#include "main.h"

int _lenb(unsigned int num)
{
	int len;

	len = 0;
	
	if (num == 0)
		return (1);

	while (num % 2 >= 0)
	{
		len++;
		num /= 2;
	}
	return (len);
}

int print_bin(unsigned int num)
{
	int i, l;
	unsigned int *bin;

	l = _lenb(num);

	if (num == 0)
	{
		print_char('0');
		return (1);
	}
	
	bin = malloc(sizeof(unsigned int) * l);
	i = 0;
	while (num > 0)
	
	{
		bin[i++] = num % 2;
		num /= 2;
	}

	for (i = i - 1; i >= 0; i--)
	{
		return (print_char('0' + bin[i]));
	}
	free(bin);
}
