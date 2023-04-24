#include "main.h"

/**
 * char_print - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int char_print(char c)
{
	return (write(1, &c, 1));
}
