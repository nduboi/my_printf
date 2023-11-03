/*
** EPITECH PROJECT, 2023
** flags
** File description:
** flags
*/
#include "includes/my_printf.h"

flags_t nbrflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    int end = 1;

    while (end != 0){
        if (format[*i + 1] <= '9' && format[*i + 1] >= '0') {
            flag_nbr.lenght = flag_nbr.lenght * 10;
            flag_nbr.lenght = flag_nbr.lenght + (format[*i + 1] - '0');
            *i = *i + 1;
            *lenght = *lenght;
            flag_nbr.y = 0;
            end = 1;
        }else{
            end = 0;
        }
    }
    return flag_nbr;
}

static flags_t precision(const char *format, int *i, int *lenght,
    flags_t flag_nbr)
{
    int end = 1;

    *i = *i + 1;
    flag_nbr.preci = 0;
    while (end != 0){
        if (format[*i + 1] <= '9' && format[*i + 1] >= '0') {
            flag_nbr.preci = flag_nbr.preci * 10;
            flag_nbr.preci = flag_nbr.preci + (format[*i + 1] - '0');
            *i = *i + 1;
            *lenght = *lenght;
            flag_nbr.y = 0;
            end = 1;
        }else{
            end = 0;
        }
    }
    flag_nbr.preci_int = flag_nbr.preci;
    return flag_nbr;
}

flags_t precflag(const char *format, int *i, int *lenght, flags_t flag_nbr)
{
    if (format[*i + 1] == '.'){
        flag_nbr = precision(format, i, lenght, flag_nbr);
    }
    return flag_nbr;
}
