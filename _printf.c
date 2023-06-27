#include  "main.h"

/**
 * _printf - Printf function
 * @format: Format of characters to be printed
 * Return: printed chars
 */

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
			{
				return (-1); 
				break;
			}
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
				len += 1;
			}
			else if (format[i] == 'd' || format[i] == 'i')
                        {
                                int num = va_arg(var, int);
                                int digits = _digits(num);
                                int d_printed = print_int(num, digits);

                                if (d_printed < 0)
                                {
                                        va_end(var);
                                        return (-1);
                                }
                                len += d_printed;
			}
			else
			{
				int c_printed = print_char('%');

				if (c_printed < 0)
				{
					len = -1;
					break;
				}
				len += 1;

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
