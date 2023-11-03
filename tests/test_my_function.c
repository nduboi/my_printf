/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** Test file for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, cflag1, .init = redirect_all_std)
{
    my_putchar('z');
    cr_assert_stdout_eq_str("z");
}

Test(my_putchar, cflag2, .init = redirect_all_std)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putchar, cflag3, .init = redirect_all_std)
{
    my_putchar('h');
    cr_assert_stdout_eq_str("h");
}

Test(my_putchar, cflag4, .init = redirect_all_std)
{
    my_putchar('Z');
    cr_assert_stdout_eq_str("Z");
}

Test(my_putchar, cflag5, .init = redirect_all_std)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putchar, cflag6, .init = redirect_all_std)
{
    my_putchar('H');
    cr_assert_stdout_eq_str("H");
}

Test(my_putchar, cflag7, .init = redirect_all_std)
{
    my_putchar('%');
    cr_assert_stdout_eq_str("%");
}

Test(my_putnbr_base, 1b8, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(0, "01234567", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr_base, 2b8, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(7, "01234567", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("7");
}

Test(my_putnbr_base, 3b8, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(8, "01234567", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("10");
}

Test(my_putnbr_base, 4b8, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(148, "01234567", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("224");
}

Test(my_putnbr_base, 1b10, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(0, "0123456789", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr_base, 2b10, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(9, "0123456789", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("9");
}

Test(my_putnbr_base, 3b10, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(10, "0123456789", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("10");
}

Test(my_putnbr_base, 4b10, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(758, "0123456789", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("758");
}
//
Test(my_putnbr_base, 1b16, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(0, "0123456789ABCDEF", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("0");
}

Test(my_putnbr_base, 2b16, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(15, "0123456789ABCDEF", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("F");
}

Test(my_putnbr_base, 3b16, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(16, "0123456789ABCDEF", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("10");
}

Test(my_putnbr_base, 4b16, .init = redirect_all_std)
{
    char src[80] = "";
    unsigned int d = -1;

    my_putnbr_base(348, "0123456789ABCDEF", src, d);
    my_putstr(my_evil_str(src));
    cr_assert_stdout_eq_str("15C");
}
//
Test(my_putstr, 1str, .init = redirect_all_std)
{
    my_putstr("");
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, 2str, .init = redirect_all_std)
{
    my_putstr("test");
    cr_assert_stdout_eq_str("test");
}

Test(my_putstr, 3str, .init = redirect_all_std)
{
    my_putstr("t");
    cr_assert_stdout_eq_str("t");
}

Test(my_putstr, 4str, .init = redirect_all_std)
{
    my_putstr("Ceci est un vrai test avec des espaces et un \n");
    cr_assert_stdout_eq_str("Ceci est un vrai test avec des espaces et un \n");
}
//
Test(my_put_nbr, 1nbr, .init = redirect_all_std)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, 2nbr, .init = redirect_all_std)
{
    my_put_nbr(8);
    cr_assert_stdout_eq_str("8");
}

Test(my_put_nbr, 3nbr, .init = redirect_all_std)
{
    my_put_nbr(14);
    cr_assert_stdout_eq_str("14");
}

Test(my_put_nbr, 4nbr, .init = redirect_all_std)
{
    my_put_nbr(18595);
    cr_assert_stdout_eq_str("18595");
}

Test(my_put_double, 1dbl, .init = redirect_all_std)
{
    my_put_double(3, 6);
    cr_assert_stdout_eq_str("3.000000");
}

Test(my_put_double, 2dbl, .init = redirect_all_std)
{
    my_put_double(0.021042, 6);
    cr_assert_stdout_eq_str("0.021042");
}

Test(my_put_double, 3dbl, .init = redirect_all_std)
{
    my_put_double(152.0000369, 6);
    cr_assert_stdout_eq_str("152.000037");
}

Test(my_put_double, 4dbl, .init = redirect_all_std)
{
    my_put_double(-3, 6);
    cr_assert_stdout_eq_str("-3.000000");
}

Test(my_put_double, 5dbl, .init = redirect_all_std)
{
    my_put_double(1.9999999, 6);
    cr_assert_stdout_eq_str("2.000000");
}

Test(my_put_double, 6dbl, .init = redirect_all_std)
{
    my_put_double(1.0999990, 6);
    cr_assert_stdout_eq_str("1.099999");
}

Test(my_put_double, 7dbl, .init = redirect_all_std)
{
    my_put_double(1.0999909, 6);
    cr_assert_stdout_eq_str("1.099991");
}

Test(exponentiel, 1e, .init = redirect_all_std)
{
    exponentiel(0.1, 6);
    cr_assert_stdout_eq_str("1.000000e-01");
}

Test(exponentiel, 2e, .init = redirect_all_std)
{
    exponentiel(0.01, 6);
    cr_assert_stdout_eq_str("1.000000e-02");
}

Test(exponentiel, 3e, .init = redirect_all_std)
{
    exponentiel(4.78957884, 6);
    cr_assert_stdout_eq_str("4.789579e+00");
}

Test(exponentiel, 4e, .init = redirect_all_std)
{
    exponentiel(14.54, 6);
    cr_assert_stdout_eq_str("1.454000e+01");
}

Test(my_put_gflag, 1gdbl, .init = redirect_all_std)
{
    my_put_gflag(1.9999999, 6);
    cr_assert_stdout_eq_str("2");
}

Test(my_put_gflag, 2gdbl, .init = redirect_all_std)
{
    my_put_gflag(-0.001234, 6);
    cr_assert_stdout_eq_str("-0.001234");
}

Test(my_put_gflag, 1gexpo, .init = redirect_all_std)
{
    my_put_gflag(-0.000000000012345, 6);
    cr_assert_stdout_eq_str("-1.2345e-11");
}

Test(my_put_gflag, 2gexpo, .init = redirect_all_std)
{
    my_put_gflag(0.000012345, 6);
    cr_assert_stdout_eq_str("1.2345e-05");
}
