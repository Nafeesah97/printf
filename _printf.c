#include  "main.h"

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
			if (format[i] == '\0')
				break;
			if (format[i] == 'c')
			{
				char ch = va_arg(var, int);
				int c_printed = print_char(ch);

				if (c_printed < 0)
				{
					len = -1;
					break;
				}
				len += c_printed;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(var, char *);
				int c_printed = print_string(str);

				if (c_printed < 0)
				{
					len = -1;
					break;
				}
				len += c_printed;
			}
			else if (format[i] == '%')
			{
				int c_printed = print_char('%');
				if (c_printed < 0)
				{
					len = -1;
					break;
				}
				len += c_printed;
			}
			else
			{
				if (print_char(format[i]) < 0)
				{
					len = -1;
					break;
				}
				len += 1;
			}
		}
		else
		{
			if (print_char(format[i]) < 0)
			{
				len = -1;
				break;
			}
			len += 1;
		}
	}
	va_end(var);
	return (len);
}
