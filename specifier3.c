/*
** EPITECH PROJECT, 2023
** specifier 3 fct
** File description:
** specifier 3 fct
*/

#include "includes/my_printf.h"

static void recup_test(long *test, va_list list)
{
    *test = va_arg(list, long);
}

static void reserch_double(double *value, va_list list)
{
    *value = va_arg(list, double);
    return;
}

int pflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    long test = 0;
    char src[80] = "";
    int d = -1;

    if (format == 'p') {
        if (flag_nbr.diez > 0){
        }
        recup_test(&test, list);
        if (test != 0) {
            my_putstr("0x");
            my_put_adresshex(test, src, d);
            my_putstr(my_evil_str(src));
            *lenght = *lenght + my_strlen(my_evil_str(src)) + 2;
        }else{
            my_putstr("(nil)");
        }
        return 1;
    }
    return 0;
}

static int print_expo(int micro_len, flags_t flag_nbr)
{
    int i = 0;

    for (i = micro_len; i < flag_nbr.lenght; i++)
        my_putchar(' ');
    return i;
}

int eflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    double double_value = 0;
    int micro_len = 0;

    if (format == 'e') {
        reserch_double(&double_value, list);
        if (flag_nbr.plus > 0 && double_value >= 0){
            micro_len = micro_len + my_putstr("+");
        }
        micro_len = micro_len + exponentiel(double_value, flag_nbr.preci);
        *lenght = *lenght + print_expo(micro_len, flag_nbr);
        return 1;
    }
    return 0;
}

int uppereflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    double double_value = 0;
    int micro_len = 0;

    if (format == 'E') {
        reserch_double(&double_value, list);
        if (flag_nbr.plus > 0 && double_value >= 0){
            micro_len = micro_len + my_putstr("+");
        }
        micro_len = micro_len + upper_exponentiel(double_value,
            flag_nbr.preci);
        *lenght = *lenght + print_expo(micro_len, flag_nbr);
        return 1;
    }
    return 0;
}

int nflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    int *n = 0;

    if (format == 'n') {
        if (flag_nbr.diez > 0){
        }
        n = va_arg(list, int *);
        *n = *n + *lenght;
        return 1;
    }
    return 0;
}

int gflag(const char format, int *lenght, va_list list, flags_t flag_nbr)
{
    double double_value = 0;
    int micro_len = 0;

    if (format == 'g' || format == 'G') {
        reserch_double(&double_value, list);
        if (flag_nbr.plus > 0 && double_value >= 0){
            micro_len = micro_len + my_putstr("+");
        }
        micro_len = micro_len + my_put_gflag(double_value, flag_nbr.preci);
        *lenght = *lenght + print_expo(micro_len, flag_nbr);
        return 1;
    }
    return 0;
}
