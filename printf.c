#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int print_num(int n);
int str_len(char *c);
int _printf(const char *format, ...);
int print_binary(int num);

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    const char *p;

    if (format == NULL)
    {
        return -1;
    }

    va_start(args, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;

            if (*p == '\0')
            {
                break;
            }

            switch (*p)
            {
            case 'c':
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                break;
            }
            case 's':
            {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                count += str_len(str);
                write(1, str, str_len(str));
                break;
            }
            case '%':
            {
                write(1, "%", 1);
                write(1, p, 1);
                count += 2;
                break;
            }
            case 'd':
            case 'i':
            {
                int num = va_arg(args, int);
                count += print_num(num);
                break;
            }
            case 'b':
            {
                int num = va_arg(args, int);
                count += print_binary(num);
                break;
            }
            //case 'u':
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
            default:
            {
                write(1, p, 1);
                count++;
                break;
            }
            }
        }
        else
        {
            write(1, p, 1);
            count++;
        }
    }

    va_end(args);

    return count;
}

int str_len(char *c)
{
    int i = 0;

    while (c[i] != '\0')
        i++;

    return i;
}

#include <unistd.h>

int print_num(int n)
{
    char buffer[1024]; // Buffer to hold digits
    int count = 0;
    int i = 0;
    unsigned int num; // Use unsigned int to handle overflow for negative numbers

    // Handle negative numbers
    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = (unsigned int)(n * -1); // Convert to unsigned to avoid overflow
    }
    else
    {
        num = n;
    }

    // Special case when n is 0
    if (num == 0)
    {
        write(1, "0", 1);
        return ++count;
    }

    // Fill buffer with digits in reverse order
    do
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    // Write digits in correct order
    while (i--)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}

int print_binary(int num)
{
    char binary[1024];
    int count = 0;

    do
    {
        if (num % 2 == 0)
        {
            binary[count] = '0';
        }
        else
        {
            binary[count] = '1';
        }
        num /= 2;
        count++;
    } while (num != 0);

    while (count--)
    {
        write(1, &binary[count], 1);
    }

    return count;
}

int main(void)
{
    unsigned int ui = (unsigned int)INT_MAX + 1024;
    int len = _printf("this is a string\n");
    printf("%d\n", len);
    _printf("String:[%s]\n", "I am a string !");
    _printf("Character:[%c]\n", 'H');
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    _printf("Len:[%i]\n", len);
    _printf("Unsigned binary:[%b,]\n", ui);
}