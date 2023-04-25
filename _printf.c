#include "main.h"

/**
 *COLLABORATION 
 * _printf -  the main function that prints
 * @format: is a character string (argument)
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
unsigned int i = 0; /*our iterator*/
unsigned int n_o_c_p = 0; /*no of characters printed*/
va_list al;

va_start(al, format);

for (i = 0; format[i] != '\0'; i++)
{
	if (format[i] != '%')
	{
		char_print(format[i]);
		n_o_c_p++;
		continue;
	}
	else
	{
		i++;
		switch (format[i])
		{
		case 'c':
			p_char(al);
			n_o_c_p++;
			continue;
		case '%':
			p_percent();
			n_o_c_p++;
			continue;
		case 's':
			n_o_c_p += p_string(al);
			continue;
		case 'd':
			n_o_c_p += p_number(al);
			continue;
		case 'i':
			n_o_c_p += p_number(al);
			continue;
		default:
			i--;
			char_print(format[i]);
			n_o_c_p++;
		}
	}
	}
	va_end(al);
	return (n_o_c_p);
}
