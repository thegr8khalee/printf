// #include "main.h"

// int _printf(const char *format, ...)
// {
//     int count = 0;
//     const char *p;
//     va_list args;
//     char flag = 0;
//     int width = 0;

//     if (format == NULL)
//     {
//         return -1;
//     }

//     va_start(args, format);

//     for (p = format; *p != '\0'; p++)
//     {
//         if (*p == '%')
//         {
//             p++;

//             if (*p == '\0')
//             {
//                 break;
//             }

//             // Reset flag for each format specifier
//             flag = 0;

//             if (*p == '+')
//             {
//                 flag = '+';
//                 p++;
//             }
//             else if (*p == '#')
//             {
//                 flag = '#';
//                 p++;
//             }
//             else if (*p == ' ')
//             {
//                 flag = ' ';
//                 p++;
//             }

//             width = 0;

//             if (isdigit(*p))
//             {
//                 width = *p - '0';
//                 p++;
//             }

//             switch (*p)
//             {
//             case 'c':
//             {
//                 char c = va_arg(args, int);
//                 write(1, &c, 1);
//                 count++;
//                 break;
//             }
//             case 's':
//             {
//                 char *str = va_arg(args, char *);
//                 if (str == NULL)
//                     str = "(null)";
//                 count += str_len(str);
//                 write(1, str, str_len(str));
//                 break;
//             }
//             case '%':
//             {
//                 char percent = '%';
//                 write(1, &percent, 1);
//                 count++;
//                 break;
//             }
//             case 'd':
//             case 'i':
//             {
//                 int integer = va_arg(args, int);
//                 count += print_num(integer, 0, flag, width);
//                 break;
//             }
//             case 'u':
//             {
//                 unsigned int num = va_arg(args, unsigned int);
//                 count += print_num(num, 1, flag, width);
//                 break;
//             }
//             case 'o':
//             {
//                 unsigned int num = va_arg(args, unsigned int);
//                 count += print_octal(num, flag, width);
//                 break;
//             }
//             case 'x':
//             {
//                 unsigned int num = va_arg(args, unsigned int);
//                 count += print_hexa(num, flag, width);
//                 break;
//             }
//             case 'X':
//             {
//                 unsigned int num = va_arg(args, unsigned int);
//                 count += print_Hexa(num, flag, width);
//                 break;
//             }
//             case 'l':
//             {
//                 p++;
//                 if (*p == 'd' || *p == 'i')
//                 {
//                     long int integer = va_arg(args, long int);
//                     count += print_num(integer, 0, flag, width);
//                 }
//                 else if (*p == 'u')
//                 {
//                     unsigned long int num = va_arg(args, unsigned long int);
//                     count += print_num(num, 1, flag, width);
//                 }
//                 else if (*p == 'o')
//                 {
//                     unsigned long int num = va_arg(args, unsigned long int);
//                     count += print_octal(num, flag, width);
//                 }
//                 else if (*p == 'x')
//                 {
//                     unsigned long int num = va_arg(args, unsigned long int);
//                     count += print_hexa(num, flag, width);
//                 }
//                 else if (*p == 'X')
//                 {
//                     unsigned long int num = va_arg(args, unsigned long int);
//                     count += print_Hexa(num, flag, width);
//                 }
//                 break;
//             }
//             case 'h':
//             {
//                 p++;
//                 if (*p == 'd' || *p == 'i')
//                 {
//                     short int integer = va_arg(args, int); // Promote short to int
//                     count += print_num(integer, 0, flag, width);
//                 }
//                 else if (*p == 'u')
//                 {
//                     unsigned short int num = va_arg(args, int); // Promote short to int
//                     count += print_num(num, 1, flag, width);
//                 }
//                 else if (*p == 'o')
//                 {
//                     short int num = va_arg(args, int); // Promote short to int
//                     count += print_octal(num, flag, width);
//                 }
//                 else if (*p == 'x')
//                 {
//                     short int num = va_arg(args, int); // Promote short to int
//                     count += print_hexa(num, flag, width);
//                 }
//                 else if (*p == 'X')
//                 {
//                     short int num = va_arg(args, int); // Promote short to int
//                     count += print_Hexa(num, flag, width);
//                 }
//                 break;
//             }
//             default:
//                 write(1, "%", 1);
//                 write(1, p, 1);
//                 count += 2;
//                 break;
//             }
//         }
//         else
//         {
//             write(1, p, 1);
//             count += 1;
//         }
//     }

//     va_end(args);
//     return (count);
// }

