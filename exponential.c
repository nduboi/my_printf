/*
** EPITECH PROJECT, 2023
** expoential function
** File description:
** exponetial fct
*/
#include <stdio.h>
#include "includes/my_printf.h"
static void divided(unsigned int *c, double *nb, int preci)
{
    double temp = 0;

    if (*nb < 0) {
        *nb = -(*nb);
        my_putchar('-');
    }
    for (*c = 0; *nb >= 10.0; *c = *c + 1) {
        temp = (int) *nb % 10;
        *nb /= 10.0 ;
    }
    if (temp >= 5 && preci == 0) {
        *nb = *nb + 1;
    }
}

static void multiply(unsigned int *d, double *nb)
{
    while (*nb < 1.0) {
        *nb *= 10.0;
        *d = *d + 1;
    }
}

static int positivexpo(int c, double nb, int preci, int caps)
{
    int lenght = 0;

    if (preci == 0)
        lenght = my_put_nbr((int) nb);
    else
        lenght = my_put_double(nb, preci);
    lenght = lenght + my_int_len(c);
    if (caps == 0) {
        if (c < 10){
            lenght = lenght + 3;
            my_printf("e+0%i", c);
        }else{
            lenght = lenght + 2;
            my_printf("e+%i", c);
        }
    }
    return lenght;
}

static int negexpo(int d, double nb, int preci, int caps)
{
    int lenght = 0;

    if (preci == 0)
        lenght = my_put_nbr((int) nb);
    else
        lenght = my_put_double(nb, preci);
    lenght = lenght + my_int_len(d);
    if (caps == 0){
        if (d < 10){
                lenght = lenght + 3;
                my_printf("e-0%i", d);
        }else{
            lenght = lenght + 2;
            my_printf("e-%i", d);
        }
    }
    return lenght;
}

int upnegexpo(int d, double nb, int preci)
{
    int lenght = 0;

    if (preci == 0)
        lenght = my_put_nbr((int) nb);
    else
        lenght = my_put_double(nb, preci);
    lenght = lenght + my_int_len(d);
    if (d < 10){
            lenght = lenght + 3;
            my_printf("E-0%i", d);
    }else{
        lenght = lenght + 2;
        my_printf("E-%i", d);
    }
    return lenght;
}

int uppositivexpo(int c, double nb, int preci)
{
    int lenght = 0;

    if (preci == 0)
        lenght = my_put_nbr((int) nb);
    else
        lenght = my_put_double(nb, preci);
    lenght = lenght + my_int_len(c);
    if (c < 10){
        lenght = lenght + 3;
        my_printf("E+0%i", c);
    } else {
        lenght = lenght + 2;
        my_printf("E+%i", c);
    }
    return lenght;
}

int exponentiel(double nb, int preci)
{
    unsigned int c = 0;
    unsigned int d = 0;
    int lenght = 0;

    divided(&c, &nb, preci);
    multiply(&d, &nb);
    if (c != 0){
        lenght = positivexpo(c, nb, preci, 0);
        return lenght;
    }
    if (d != 0){
        lenght = negexpo(d, nb, preci, 0);
        return lenght;
    }
    if (preci == 0)
        lenght = my_put_nbr((int) nb) + 4;
    else
        lenght = my_put_double(nb, preci) + 4;
    my_printf("e+0%i", nb, 0);
    return lenght;
}

int upper_exponentiel(double nb, int preci)
{
    unsigned int c = 0;
    unsigned int d = 0;
    int lenght = 0;

    divided(&c, &nb, preci);
    multiply(&d, &nb);
    if (c != 0){
        lenght = uppositivexpo(c, nb, preci);
        return lenght;
    }
    if (d != 0){
        lenght = upnegexpo(d, nb, preci);
        return lenght;
    }
    if (preci == 0)
        lenght = my_put_nbr((int) nb) + 4;
    else
        lenght = my_put_double(nb, preci) + 4;
    my_printf("E+0%i", 0);
    return lenght;
}
