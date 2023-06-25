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
				print_char(ch);
				if (print_char(ch) < 0)
				{
					len = -1;
					break;
				}
				len++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(var, char *);
				int strlen = print_string(str);

				print_string(str);
				if (print_string(str) < 0)
				{
					len = -1;
					break;
				}
				len += strlen;
			}
			else if (format[i] == '%')
			{
				print_char('%');
				if (print_char('%') < 0)
				{
					len = -1;
					break;
				}
				len++;
			}
			else
			{
				print_char(format[i]);
				if (print_char(format[i]) < 0)
				{
					len = -1;
					break;
				}
				len += 2;
			}
		else
		{
			print_char(format[i]);
			if (print_char(format[i]) < 0)
			{
				len = -1;
				break;
			}
			len++;
		}
	}
	va_end(var);
	return (len);
}
