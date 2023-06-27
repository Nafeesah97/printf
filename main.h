#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_int(int num, int digits);
int _digits(int num);

#endif
