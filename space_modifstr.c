/*
** EPITECH PROJECT, 2023
** modifspace function
** File description:
** modifspace file 1
*/
#include "includes/my_printf.h"


void my_putstrn(char *src, int n)
{
    for (int i = 0; i < n; i++)
        my_putchar(src[i]);
    return;
}

int printlen_str(char *src, int len, flags_t flags_nbr)
{
    int i = 0;

    if (flags_nbr.preci != 6) {
        len = flags_nbr.preci_int;
        for (i = len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
        if (len >= flags_nbr.preci_int)
            my_putstrn(src, flags_nbr.preci_int);
        else
            my_putstrn(src, len);
        return i;
    }
    if (flags_nbr.preci_int == 0 && flags_nbr.preci == 6) {
        len = my_strlen(src);
        for (i = len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
        my_putstr(src);
        return i;
    }
    return i;
}

int printlenmenos_str(char *src, int len, flags_t flags_nbr)
{
    int i = 0;

    if (flags_nbr.preci != 6) {
        if (len >= flags_nbr.preci_int){
            len = flags_nbr.preci_int;
            my_putstrn(src, flags_nbr.preci_int);
        }else
            my_putstrn(src, len);
        for (i = len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
        return i;
    }
    if (flags_nbr.preci_int == 0 && flags_nbr.preci == 6) {
        len = my_strlen(src);
        my_putstr(src);
        for (i = len; i < flags_nbr.lenght; i++)
            my_putchar(' ');
        return i;
    }
    return i;
}

int printcla_str(char *src, int len, flags_t flags_nbr)
{
    if (flags_nbr.preci != 6) {
        if (len >= flags_nbr.preci_int) {
            my_putstrn(src, flags_nbr.preci_int);
            len = flags_nbr.preci_int;
        }else
            my_putstrn(src, len);
        return len;
    }
    if (flags_nbr.preci_int == 0 && flags_nbr.preci == 6) {
        len = my_strlen(src);
        my_putstr(src);
        return len;
    }
    return 0;
}

int print_str(int len, char *src, flags_t flags_nbr)
{
    if (flags_nbr.lenght > 0 && flags_nbr.menos == 0) {
        return printlen_str(src, len, flags_nbr);
    }
    if (flags_nbr.lenght > 0 && flags_nbr.menos > 0) {
        return printlenmenos_str(src, len, flags_nbr);
    }
    return printcla_str(src, len, flags_nbr);
}
