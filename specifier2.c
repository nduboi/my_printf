/*
** EPITECH PROJECT, 2023
** specifier fucntion
** File description:
** specifer part 2
*/

#include "includes/my_printf.h"

static void reserch_double(double *value, va_list list)
{
    *value = va_arg(list, double);
    return;
}

int uflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    if (format == 'u') {
        if (flag_nbr.diez > 0) {
        }
        *lenght = *lenght + my_put_unsigned(va_arg
        (list, unsigned int));
        return 1;
    }
    return 0;
}

static int complete_zero(int src, flags_t flag_nbr)
{
    int micro_len = 0;

    for (int i = src; i < flag_nbr.preci; i++) {
        micro_len = micro_len + 1;
    }
    return micro_len;
}

int xflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    char src[80] = "";
    unsigned int d = -1;
    int micro_len = 0;

    if (format == 'x') {
        if (flag_nbr.diez > 0){
            micro_len = micro_len + 2;
        }
        my_putnbr_base(va_arg(
        list, unsigned int), "0123456789abcdef", src, d);
        micro_len = micro_len + my_strlen(my_evil_str(src));
        if (flag_nbr.preci_int > 0) {
            micro_len = micro_len + complete_zero(my_strlen(src), flag_nbr);
        }
        *lenght = *lenght + print_base(src, micro_len, flag_nbr, "0x");
        return 1;
    }
    return 0;
}

int upperxflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    char src[80] = "";
    unsigned int d = -1;
    int micro_len = 0;

    if (format == 'X') {
        if (flag_nbr.diez > 0){
            micro_len = micro_len + 2;
        }
        my_putnbr_base(va_arg(
        list, unsigned int), "0123456789ABCDEF", src, d);
        micro_len = micro_len + my_strlen(my_evil_str(src));
        if (flag_nbr.preci_int > 0) {
            micro_len = micro_len + complete_zero(my_strlen(src), flag_nbr);
        }
        *lenght = *lenght + print_base(src, micro_len, flag_nbr, "0X");
        return 1;
    }
    return 0;
}

int bflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    char src[80] = "";
    unsigned int d = -1;
    int micro_len = 0;

    if (format == 'b') {
        if (flag_nbr.diez > 0){
            micro_len = micro_len + 2;
        }
        my_putnbr_base(va_arg(
        list, unsigned int), "01", src, d);
        micro_len = micro_len + my_strlen(my_evil_str(src));
        if (flag_nbr.preci_int > 0) {
            micro_len = micro_len + complete_zero(my_strlen(src), flag_nbr);
        }
        *lenght = *lenght + print_base(src, micro_len, flag_nbr, "0b");
        return 1;
    }
    return 0;
}

static int printfloat(int micro_len, flags_t flag_nbr)
{
    int i = 0;

    for (i = micro_len; i < flag_nbr.lenght; i++)
        my_putchar(' ');
    return i;
}

int fflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    double double_value = 0;
    int micro_len = 0;

    if (format == 'f' ||
        format == 'F') {
        reserch_double(&double_value, list);
        if (flag_nbr.plus > 0 && double_value >= 0){
            micro_len = micro_len + my_putstr("+");
        }
        micro_len = micro_len + my_put_double(double_value, flag_nbr.preci);
        *lenght = *lenght + printfloat(micro_len, flag_nbr);
        return 1;
    }
    return 0;
}
