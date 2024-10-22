// #include "main.h"

// int print_num(unsigned int n, int is_unsigned, char flag, int x)
// {
//     int count = 0;
//     char buffer[12]; // Enough for 32-bit unsigned integer
//     int i = 0;
//     unsigned int num;

//     // Handle negative numbers if not unsigned
//     if (!is_unsigned && (int)n < 0)
//     {
//         write(1, "-", 1);
//         count++;
//         num = -((int)n); // Use negative value for proper conversion
//     }
//     else
//     {
//         num = n;
//     }

//     // Convert number to string in reverse
//     do
//     {
//         buffer[i++] = (num % 10) + '0';
//         num /= 10;
//     } while (num > 0);

//     // Handle flag for positive numbers
//     if (flag == '+' && !is_unsigned && (int)n >= 0)
//     {
//         write(1, "+", 1);
//         count++;
//     }
//     else if (flag == ' ')
//     {
//         write(1, " ", 1);
//         count++;
//     }

//     // Determine how many characters to print (max of buffer length or x)
//     int chars_to_print = (x < i) ? x : i;

//     // Print the number from the buffer in reverse order
//     for (int j = chars_to_print - 1; j >= 0; j--)
//     {
//         write(1, &buffer[j], 1);
//         count++;
//     }

//     return count;
// }

// int print_binary(int n, char flag, int width)
// {
//     int count = 0;
//     char binary[1024];

//     do
//     {
//         if ((n % 2) == 0)
//             binary[count] = '0';
//         else
//             binary[count] = '1';
//         n /= 2;
//         count++;
//     } while (n != 0);

//     // char temp[1024];

//     if (flag == '#')
//     {
//         write(1, "0b", 2);
//         count += 2;
//     }
//     else if (flag == ' ')
//     {
//         write(1, " ", 1);
//         count++;
//     }

//     if (width == 0)
//     {
//         width = count - 1;
//     }

//     for (int i = width; i >= 0; i--)
//     {
//         write(1, &binary[i], 1);
//     }

//     return count;
// }


int str_len(char *c)
{
    int i = 0;

    while (c[i] != '\0')
        i++;

    return i;
}
// int print_octal(unsigned int num, char flag, int width)
// {
//     int count = 0;
//     char octal[12]; // Enough for 32-bit unsigned integer

//     do
//     {
//         octal[count++] = (num % 8) + '0';
//         num /= 8;
//     } while (num != 0);

//     if (flag == '#')
//     {
//         write(1, "0", 1);
//         count++;
//     }

//     if (width == 0)
//     {
//         width = count - 1;
//     }

//     for (int i = width; i >= 0; i--)
//     {
//         write(1, &octal[i], 1);
//     }

//     return count;
// }

// int print_hexa(unsigned int num, char flag, int width)
// {
//     int count = 0;
//     char hexa[1024];
//     char temp;

//     if (flag == '#')
//     {
//         write(1, "0x", 2);
//         count += 2;
//     }
//     else if (flag == ' ')
//     {
//         write(1, " ", 1);
//         count++;
//     }

//     do
//     {
//         temp = (num % 16);
//         if (temp == 10)
//         {
//             hexa[count] = 'a';
//         }
//         else if (temp == 11)
//         {
//             hexa[count] = 'b';
//         }
//         else if (temp == 12)
//         {
//             hexa[count] = 'c';
//         }
//         else if (temp == 13)
//         {
//             hexa[count] = 'd';
//         }
//         else if (temp == 14)
//         {
//             hexa[count] = 'e';
//         }
//         else if (temp == 15)
//         {
//             hexa[count] = 'f';
//         }
//         else
//         {
//             hexa[count] = temp + '0';
//         }
//         num /= 16;
//         count++;
//     } while (num != 0);

//     if (width == 0)
//     {
//         width = count - 1;
//     }

//     for (int i = width; i >= 0; i--)
//     {
//         write(1, &hexa[i], 1);
//     }

//     return count;
// }

// int print_Hexa(unsigned int num, char flag, int width)
// {
//     int count = 0;
//     char hexa[1024];
//     char temp;

//     if (flag == '#')
//     {
//         write(1, "0x", 2);
//         count += 2;
//     }
//     else if (flag == ' ')
//     {
//         write(1, " ", 1);
//         count++;
//     }

//     do
//     {
//         temp = (num % 16);
//         if (temp == 10)
//         {
//             hexa[count] = 'A';
//         }
//         else if (temp == 11)
//         {
//             hexa[count] = 'B';
//         }
//         else if (temp == 12)
//         {
//             hexa[count] = 'C';
//         }
//         else if (temp == 13)
//         {
//             hexa[count] = 'D';
//         }
//         else if (temp == 14)
//         {
//             hexa[count] = 'E';
//         }
//         else if (temp == 15)
//         {
//             hexa[count] = 'F';
//         }
//         else
//         {
//             hexa[count] = temp + '0';
//         }
//         num /= 16;
//         count++;
//     } while (num != 0);

//     if (width == 0)
//     {
//         width = count - 1;
//     }

//     for (int i = width; i >= 0; i--)
//     {
//         write(1, &hexa[i], 1);
//     }

//     return count;
// }


// while (alive() == true) {
//     bitches.fuck();
//     code();
//     money.get();
// }