#include  "main.h"

int _printf(const char *format, ...)
{
	int i, len;
	va_list var;

	va_start(var, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == 'c')
			{
				char ch = va_arg(var, int);
				if (print_char(ch) < 0)
				{
					len = -1;
					break;
				}
				len += print_char(ch);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(var, char *);
				int stlen = print_string(str);

				if (print_string(str) < 0)
				{
					len = -1;
					break;
				}
				len += stlen;
			}
			else if (format[i] == '%')
			{
				if (print_char('%') < 0)
				{
					len = -1;
					break;
				}
				len += print_char('%');
			}
			else
			{
				if (print_char(format[i]) < 0)
				{
					len = -1;
					break;
				}
				len += print_char(format[i]);
			}
		}
		else
		{
			if (print_char(format[i]) < 0)
			{
				len = -1;
				break;
			}
			len += print_char(format[i]);
		}
	}
	va_end(var);
	return (len);
}
