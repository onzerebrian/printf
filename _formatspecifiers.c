#include "main.h"

/**
 * p_char - %c function printer
 * @x: the character arguments list
 * Return: returns 1 - no of chars printed
 */

int p_char(va_list x)
{
	char_print(va_arg(x, int));
	return (1);
}

/**
 * p_string - %s function printer
 * @al: the string arguments list
 * Return: returns 1 - no of chars printed
 */
int p_string(va_list al)
{
	int i;
	char *s;

	s = va_arg(al, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	for (i = 0; s[i] != '\0'; i++)
	{
	char_print(s[i]);
	}
	return (i);
}

/**
 * p_percent - %% function printer
 * Return: returns 1 - no of % printed
 */
int p_percent(void)
{
	char_print('%');
	return (0);
}

/**
 * p_number - %d and %i
 * @al:integer  arguments
 * Return: the length of integer
 */
int p_number(va_list al)
{
	unsigned int m;
	int i, d, e;

	i = va_arg(al, int);
	d = 1;
	e = 0;

	if (i < 0)
	{
		e = e + char_print('-');
		m = i * -1;
	}
	else
	{
		m = i;
	}
	for (; m / d > 9;)
	{
		d = d * 10;
	}
	for (; d != 0;)
	{
		e += char_print('0' + m / d);
		m %= d;
		d /= 10;
	}
	return (e);
}

