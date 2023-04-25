#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;
    char char_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 's':
                    str_arg = va_arg(args, char *);
                    while (*str_arg)
                    {
                        printed_chars += write(1, str_arg, 1);
                        str_arg++;
                    }
                    break;
                case 'c':
                    char_arg = va_arg(args, int);
                    printed_chars += write(1, &char_arg, 1);
                    break;
                case '%':
                    printed_chars += write(1, "%", 1);
                    break;
                default:
                    printed_chars += write(1, "%", 1);
                    printed_chars += write(1, format, 1);
                    break;
            }
        }
        else
        {
            printed_chars += write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return (printed_chars);
}
