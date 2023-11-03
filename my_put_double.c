/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** Display a float to the decimal notation
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

int print_stock(int stock, int n)
{
    int div = my_compute_power_rec(10, n);
    int to_print = 0;

    for (int i = 0; i < n; i++) {
        to_print = (stock / div) % 10;
        div = div / 10;
        my_putchar(to_print + 48);
    }
    return (n);
}

static int stock_after_comma(double nb, int n)
{
    int result = 0;
    int next_result = 0;
    int stock = 0;
    int multiply = 10;
    int x = 0;

    stock = (10 * my_compute_power_rec(10, n)) + 1;
    x = (stock - 1) / 10;
    for (int i = 0; i < n; i++) {
        result = nb * multiply;
        next_result = nb * (multiply * 10);
        stock = stock + ((result % 10) * x);
        multiply = multiply * 10;
        x = x / 10;
        if (i == (n - 1) && next_result % 10 >= 5)
            stock = stock + 10;
    }
    return (print_stock(stock, n));
}

int my_put_double(double nb, int preci)
{
    int n = preci;
    int len = 0;
    int round = 0;

    nb = check_negative(nb, &len);
    round = check_if_round(nb, n);
    if (round == 1) {
        len = len + my_put_nbr((int) nb + 1);
        if (n == 0)
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
