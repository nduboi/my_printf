/*
** EPITECH PROJECT, 2023
** flags
** File description:
** flags
*/
#include "includes/my_printf.h"

flags_t diezflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == '#') {
        flag_nbr.diez = flag_nbr.diez + 1;
        flag_nbr.y = 1;
        *i = *i + 1;
        *lenght = *lenght;
        return flag_nbr;
    }
    return flag_nbr;
}

flags_t blankflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == ' ') {
        flag_nbr.blank = flag_nbr.blank + 1;
        flag_nbr.y = 1;
        *i = *i + 1;
        *lenght = *lenght;
        return flag_nbr;
    }
    return flag_nbr;
}

flags_t menosflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == '-') {
        flag_nbr.menos = flag_nbr.menos + 1;
        flag_nbr.y = 1;
        *i = *i + 1;
        *lenght = *lenght;
        return flag_nbr;
    }
    return flag_nbr;
}

flags_t plusflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == '+') {
        flag_nbr.plus = flag_nbr.plus + 1;
        flag_nbr.y = 1;
        *i = *i + 1;
        *lenght = *lenght;
        return flag_nbr;
    }
    return flag_nbr;
}

flags_t zeroflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == '0') {
        flag_nbr.zero = flag_nbr.zero + 1;
        flag_nbr.y = 1;
        *i = *i + 1;
        *lenght = *lenght;
        return flag_nbr;
    }
    return flag_nbr;
}
