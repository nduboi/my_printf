/*
** EPITECH PROJECT, 2023
** modifspace function
** File description:
** modifspace file 1
*/
#include "includes/my_printf.h"

int printlenmenos(char *src, int value, int len, flags_t flags_nbr)
{
    int i = 0;

    if (value > 0 && flags_nbr.plus > 0)
        my_putchar('+');
    if (value < 0)
        my_putchar('-');
    for (int k = my_strlen(src); k < flags_nbr.preci_int; k++)
        my_putstr("0");
    my_putstr(src);
    for (i = len; i < flags_nbr.lenght; i++)
        my_putchar(' ');
    return i;
}

int printlen(char *src, int value, int len, flags_t flags_nbr)
{
    int i = 0;

    for (i = len; i < flags_nbr.lenght; i++) {
        my_putchar(' ');
    }
    if (value > 0 && flags_nbr.plus > 0)
        my_putchar('+');
    if (value < 0)
        my_putchar('-');
    for (int k = my_strlen(src); k < flags_nbr.preci_int; k++)
        my_putchar('0');
    my_putstr(src);
    return i;
}

int printcla(char *src, int value, int len, flags_t flags_nbr)
{
    if (value > 0 && flags_nbr.plus > 0)
        my_putchar('+');
    if (value < 0)
        my_putchar('-');
    for (int k = my_strlen(src); k < flags_nbr.preci_int; k++)
        my_putchar('0');
    my_putstr(src);
    return len;
}

int printall(char *src, int value, int len, flags_t flags_nbr)
{
    if (flags_nbr.lenght > 0 && flags_nbr.menos == 0) {
        return printlen(src, value, len, flags_nbr);
    }
    if (flags_nbr.lenght > 0 && flags_nbr.menos > 0) {
        return printlenmenos(src, value, len, flags_nbr);
    }
    return printcla(src, value, len, flags_nbr);
}
