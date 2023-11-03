/*
** EPITECH PROJECT, 2023
** my_put_gflag
** File description:
** Choose between f or e flag depending of the precision
*/

#include "includes/my_printf.h"

static double check_negative(double nb, int *len)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        *len = *len + 1;
    }
    return (nb);
}

static int check_if_round(double nb, int n)
{
    int result = 0;
    int multiply = 10;
    int next_result = 0;

    for (int i = 0; i < n; i++) {
        result = nb * multiply;
        next_result = nb * (multiply * 10);
        multiply = multiply * 10;
        if (result % 10 != 9 || next_result % 10 < 5) {
            return (0);
        }
    }
    if (n == 0)
        result = nb * 10;
    if (result % 10 < 5)
        return (0);
    return (1);
}

static int print_stock(int stock, int n)
{
    int div = my_compute_power_rec(10, n) / 10;
    int to_check = 0;
    int to_print = 0;
    int end_zero = 0;

    for (int i = 0; i < n; i++) {
        to_check = (stock / div) % 10;
        div = div / 10;
        if (to_check == 0)
            end_zero++;
        else
            end_zero = 0;
    }
    div = my_compute_power_rec(10, n) / 10;
    for (int j = 0; j < (n - end_zero); j++) {
        to_print = (stock / div) % 10;
        div = div / 10;
        my_putchar(to_print + 48);
    }
    return (n - end_zero);
}

static int count_zero(double nb)
{
    int to_check = 0;
    int mul = 10;
    int zero = 0;

    for (int i = 0; i < 3; i++) {
        to_check = nb * mul;
        to_check = to_check % 10;
        mul = mul * 10;
        if (to_check == 0)
            zero++;
        else
            return (zero);
    }
    return (zero);
}

static int stock_after_comma(double nb, int n)
{
    int result = 0;
    int next_result = 0;
    int multiply = 10;
    int stock = 0;
    int x = 0;

    n = n + count_zero(nb);
    stock = 1 * my_compute_power_rec(10, n);
    x = stock / 10;
    for (int i = 0; i < n; i++) {
        result = nb * multiply;
        next_result = nb * (multiply * 10);
        stock = stock + ((result % 10) * x);
        x = x / 10;
        multiply = multiply * 10;
        if (i == (n - 1) && next_result % 10 >= 5)
            stock = stock + 1;
    }
    return (print_stock(stock, n));
}

int my_print_double(double nb, int preci)
{
    int n = preci;
    int len = 0;
    int round = 0;

    round = check_if_round(nb, n);
    if (round == 1) {
        len = len + my_put_nbr((int) nb + 1);
        return (len);
    } else {
        len = len + my_put_nbr((int) nb);
        if (n == 0)
            return (len);
    }
    my_putchar('.');
    len = len + stock_after_comma(nb, n);
    return (len + 1);
}

void multiply(unsigned int *d, double *nb)
{
    while (*nb < 1.0) {
        *nb *= 10.0;
        *d = *d + 1;
    }
}

int my_put_gflag(double nb, int preci)
{
    unsigned int d = 0;
    double nbr = 0;
    int len = 0;

    nb = check_negative(nb, &len);
    nbr = nb;
    multiply(&d, &nb);
    if (d <= 4) {
        len = len + my_print_double(nbr, preci);
        return (len);
    }
    len = len + my_int_len(d);
    if (d < 10) {
        len = (len + 3) + my_print_double(nb, preci);
        my_printf("e-0%i", d);
    } else {
        len = (len + 2) + my_print_double(nb, preci);
        my_printf("e-%i", d);
    }
    return (len);
}
