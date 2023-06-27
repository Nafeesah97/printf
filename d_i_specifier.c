#include "main.h"

int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list var;

	va_start(var, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(var, int);
				int digits = _digits(num);
				int d_printed - print_int(num, digits);

				if (d_printed < 0)
				{
					va_end(var);
					return (-1);
				}
				len += d_printed;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(var, char *);
				int c_printed = print_string(str);

				if (c_printed < 0)
				{
					va_end(var);
					return (-2);
				}
				len += c_printed;
			}
			else
			{
				int c_printed = print_char(format[i]);
				if (c_printed < 0)
				{
					va_end(var);
					return (-3);
				}
				len += c_printed;
			}
		}
		else
		{
			int c_printed = print_char(format[i]);
			if (c_printed < 0)
			{
				va_end(var);
				return (-4);
			}
			len += c_printed;
		}
	}

	va_end(var);
	return (len);
}
