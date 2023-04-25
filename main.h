#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


int _printf(const char *format, ...);
int output_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/**int p_char(va_list al);
* int char_print(char c);
* int p_string(va_list al);
* int p_percent();
*/ int p_number(va_list al);
#endif
