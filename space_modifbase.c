/*
** EPITECH PROJECT, 2023
** specifier function
** File description:
** specifier file 1
*/
#include <stdio.h>
#include "includes/my_printf.h"

int print_base(char *src, int micro_len, flags_t flags_nbr, char *opt)
{
    int i = micro_len;
    int octal_zero = 0;

    if (flags_nbr.diez >= 1 && my_strcmp(opt, "0") == 0)
        octal_zero++;
    if (flags_nbr.lenght > 0 && flags_nbr.menos == 0) {
        for (i = micro_len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
    }
    if (flags_nbr.diez >= 1)
        my_putstr(opt);
    for (int k = my_strlen(src) + octal_zero; k < flags_nbr.preci_int; k++)
        my_putchar('0');
    my_putstr(src);
    if (flags_nbr.lenght > 0 && flags_nbr.menos > 0) {
        for (i = micro_len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
    }
    return i;
}
