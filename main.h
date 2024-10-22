#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

// Prototypes for the functions
int _printf(const char *format, ...);
int print_num(unsigned int n, int is_unsigned, char flag, int width);
int print_octal(unsigned int num, char flag, int width);
int print_hexa(unsigned int num, char flag, int width);
int print_Hexa(unsigned int num, char flag, int width);
int str_len(char *c);
int print_binary(int n, char flag, int width);

#endif // MAIN_H
