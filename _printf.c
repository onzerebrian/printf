#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _ptintf - custom implementation of printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _ptintf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);
						fputs(s, stdout);
						count += strlen(s);
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				default:
					{
						putchar('%');
						putchar(*ptr);
						count += 2;
						break;
					}
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
		ptr++;
	}

	va_end(args);

	return count;
}
