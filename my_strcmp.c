/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare two string and return a int indicating the result
*/

#include "includes/my_printf.h"

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;

    for (int i = 0; i < 2; i++) {
        if (s1[i] < s2[i]) {
            result = -1;
            return (result);
        }
        if (s1[i] > s2[i]) {
            result = 1;
            return (result);
        }
    }
    return (result);
}
