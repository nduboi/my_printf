/*
** EPITECH PROJECT, 2023
** specifier function
** File description:
** specifier file 1
*/
#include "includes/my_printf.h"
#include <stdlib.h>

static void reserch_ineger(int *value, va_list list)
{
    *value = va_arg(list, int);
    return;
}

static int complete_zero(int src, flags_t flag_nbr)
{
    int micro_len = 0;

    for (int i = src; i < flag_nbr.preci; i++) {
        micro_len = micro_len + 1;
    }
    return micro_len;
}

int cflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    if (format == 'c') {
        if (flag_nbr.blank > 0){
        }
        my_putchar(va_arg(list, int));
        *lenght = *lenght + 1;
        return 1;
    }
    return 0;
}

int oflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    char src[30] = "";
    unsigned int d = -1;
    int micro_len = 0;

    if (format == 'o') {
        my_putnbr_base(va_arg(
            list, unsigned int), "01234567", src, d);
        micro_len = micro_len + my_strlen(my_evil_str(src));
        if (flag_nbr.preci_int > 0) {
            micro_len = micro_len + complete_zero(my_strlen(src), flag_nbr);
        }
        *lenght = *lenght + print_base(src, micro_len, flag_nbr, "0");
        return 1;
    }
    return 0;
}

static int recup_str(char **src, va_list list)
{
    *src = va_arg(list, char *);
    return my_strlen(*src);
}

int sflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    int micro_len = 0;
    char *src;

    if (format == 's') {
        if (flag_nbr.blank > 0){
        }
        micro_len = recup_str(&src, list);
        *lenght = *lenght + print_str(micro_len, src, flag_nbr);
        return 1;
    }
    return 0;
}

int idflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    int integer_value = 0;
    char src[80] = "";
    int micro_len = 0;

    if (format == 'i' || format == 'd') {
        reserch_ineger(&integer_value, list);
        if (flag_nbr.plus > 0 && integer_value >= 0){
            micro_len = micro_len + 1;
        }
        if (integer_value < 0) {
            micro_len = micro_len + 1;
        }
        micro_len = micro_len + my_strlen(my_stock_nbr(integer_value, src));
        if (flag_nbr.preci_int > 0) {
            micro_len = micro_len + complete_zero(my_strlen(src), flag_nbr);
        }
        *lenght = *lenght + printall(src, integer_value, micro_len, flag_nbr);
        return 1;
    }
    return 0;
}

int prcflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    if (format == '%') {
        if (flag_nbr.blank > 0 ){
        }
        my_putchar('%');
        *lenght = *lenght + 1;
        list = list;
        return 1;
    }
    return 0;
}
