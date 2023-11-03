/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** Write a character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
