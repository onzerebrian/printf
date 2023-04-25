#ifndef PRINT_H
#define PRINT_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int p_char(va_list al);
int char_print(char c);
int p_string(va_list al);
int p_percent();
int p_number(va_list al);
#endif  /* PRINT_H */
