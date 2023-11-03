/*
** EPITECH PROJECT, 2023
** my_put_long
** File description:
** fct
*/
#include "includes/my_printf.h"

static char *long_max(void)
{
    return "-9223372036854775807";
}

static char negativ(int *d)
{
    *d = *d + 1;
    return '-';
}

char *my_put_adresshex(long nbr, char *src, int d)
{
    long c;
    char base[] = "0123456789abcdef";

    d++;
    if (nbr == -9223372036854775807) {
        src = long_max();
    }else{
        if (nbr < 0) {
            src[0] = negativ(&d);
            nbr = nbr * -1;
        }
        if (nbr >= 16){
            c = nbr % 16;
            my_put_adresshex(nbr / 16, src, d);
            src[d] = base[c];
        }else{
            src[d] = base[nbr];
        }
    }
    return src;
}
