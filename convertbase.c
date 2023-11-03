/*
** EPITECH PROJECT, 2023
** convert base
** File description:
** convert base
*/
#include "includes/my_printf.h"

char *my_putnbr_base(unsigned int nbr, char const *base,
    char *src, unsigned int d)
{
    unsigned int c;
    unsigned int len = my_strlen(base);

    d++;
    if (nbr >= len) {
        c = nbr % len;
        my_putnbr_base(nbr / len, base, src, d);
        src[d] = base[c];
    }else {
        src[d] = base[nbr];
    }
    return src;
}
