#ifndef MAIN_H
#define MAIN_H

#define BUF_SIZE 1024

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int not_ld(void);
int is_len_mod(const char *format);
int is_len_mod(const char *format);
int _isflag(const char *format);
int _islower(int c);
int _isdigit(char c);
int _isalpha(int c);
int _strlen(const char *str);
int *_strncpy(char *dest, char *src, int n);
void reverse_strung(char *str, int length);

/* handle flags, length modifiers, field woth and precision */
int handle_flags(const char *format, va_list args, int count);
int handle_len_mod(char len_mod, const char *format, va_list args, int count);
int handle_width(const char *format, va_list args, int count);
int handle_precision(const char *format, va_list args, int count);
int handle_conversion(const char *format, va_list args);

/* print with precision */
int print_float(double num, int precision);
int print_string_with_precision(char *str, int precision);

/* get length */
int get_length_ilunsigned(unsigned int num);
int get_length_int(int num);
int get_length_float(double num);

/* peinting functions */
int _putchar(char c);
int _printf(const char *format, ...);
int print_percent(void);
int print_char(va_list args);
int print_strings(va_list args);
int print_nonprintable(va_list args);
int print_int(int num);
int print_bin(unsigned int num);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hex_lower(unsigned int num);
int print_hex_upper(unsigned int num);
int print_pointer(void *ptr);
int print_rot13_string(char *str);
int print_reversed_string(char *str);

#endif
