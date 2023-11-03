/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Whole printf function
*/

#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include "includes/my_printf.h"

int (*spe[])(const char format, int *lenght,
    va_list list, flags_t flag_nbr) = {cflag, sflag, idflag, prcflag,
    oflag, uflag, xflag, upperxflag, bflag, fflag, pflag, eflag,
    uppereflag, nflag, gflag};

flags_t(*flags[])(const char *format, int *i, int *lenght,
    flags_t flag_nbr) = {diezflag, blankflag, menosflag, plusflag,
    zeroflag, nbrflag, precflag};

static struct flags ini_node(flags_t flag_nbr)
{
    flag_nbr.diez = 0;
    flag_nbr.blank = 0;
    flag_nbr.menos = 0;
    flag_nbr.plus = 0;
    flag_nbr.zero = 0;
    flag_nbr.lenght = 0;
    flag_nbr.preci = 6;
    flag_nbr.preci_int = 0;
    flag_nbr.y = 0;
    return flag_nbr;
}

static void print_ext(char c, int *i)
{
    my_putchar(c);
    *i = *i + 1;
    return;
}

flags_t find_flag(const char *format, int *i, int *lenght, va_list list)
{
    int x = 0;
    flags_t flag_nbr;

    flag_nbr = ini_node(flag_nbr);
    for (int j = 0; j < 7; j++) {
        flag_nbr = flags[j] (format, i, lenght, flag_nbr);
        if (flag_nbr.y == 1) {
            flag_nbr.y = 0;
            j = -1;
        }
    }
    for (int k = 0; k < 15; k++) {
        x += spe[k] (format[*i + 1], lenght, list, flag_nbr);
    }
    if (x != 0) {
        *i += 2;
        return flag_nbr;
    }
    print_ext('%', i);
    return flag_nbr;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int lenght = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            find_flag(format, &i , &lenght, list);
        } else {
            my_putchar(format[i]);
            i++;
            lenght = lenght + 1;
        }
    }
    va_end(list);
    return (lenght);
}
