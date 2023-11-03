/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Display all the possible values of an int
*/

#include "includes/my_printf.h"

int my_unsigned_len(unsigned int nb)
{
    int len = 0;

    if (nb == 0) {
        return (1);
    }
    while (nb != 0) {
        nb /= 10;
        len += 1;
    }
    return (len);
}

int my_put_unsigned(unsigned int nb)
{
    int divided = 1;
    int result_nb = 0;

    for (int i = 0; i < (my_unsigned_len(nb) - 1); i++)
        divided = divided * 10;
    for (int j = 0; j < my_unsigned_len(nb); j++ ) {
        result_nb = (nb / divided) % 10;
        divided = divided / 10;
        my_putchar(result_nb + 48);
    }
    return (my_unsigned_len(nb));
}
