/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Prototype of my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

typedef struct flags{
    int diez;
    int menos;
    int plus;
    int zero;
    int blank;
    int lenght;
    int preci;
    int preci_int;
    int y;
} flags_t ;

void my_putchar(char c);
int my_put_nbr(int nb);
char *my_stock_nbr(int nb, char *src);
char *my_put_adresshex(long nb, char *src, int d);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_compute_power_rec(int nb, int power);
int my_put_unsigned(unsigned int nb);
char *my_putnbr_base(unsigned int nbr, char const *base,
    char *src, unsigned int d);
int my_int_len(int nb);
char *my_evil_str(char *str);
int my_put_double(double nb, int preci);
int my_put_gflag(double nb, int preci);
int my_strlen(char const *str);
int exponentiel(double nb, int preci);
int upper_exponentiel(double nb, int preci);
flags_t find_flag(const char *format, int *i, int *add_lenght, va_list list);
int my_printf(const char *format, ...);
int cflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int sflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int idflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int prcflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int oflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int uflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int xflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int upperxflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int bflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int fflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int pflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int eflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int nflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int uppereflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
int gflag(const char format, int *lenght, va_list list, flags_t flag_nbr);
char *my_strcat(char *dest, char const *src);
flags_t diezflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t blankflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t menosflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t plusflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t zeroflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t nbrflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
flags_t precflag(const char *format, int *i, int *lenght, flags_t flag_nbr);
int printall(char *src, int value, int len, flags_t flags_nbr);
int printcla(char *src, int value, int len, flags_t flags_nbr);
int printlen(char *src, int value, int len, flags_t flags_nbr);
int printlenmenos(char *src, int value, int len, flags_t flags_nbr);
void my_putstrn(char *src, int n);
int printlen_str(char *src, int len, flags_t flags_nbr);
int printlenmenos_str(char *src, int len, flags_t flags_nbr);
int printcla_str(char *src, int len, flags_t flags_nbr);
int print_str(int len, char *src, flags_t flags_nbr);
int print_base(char *src, int micro_len, flags_t flag_nbr, char *opt);

#endif /* MY_PRINTF_H_ */
