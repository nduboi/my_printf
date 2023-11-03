/*
** EPITECH PROJECT, 2023
** my_evil_str
** File description:
** The goal of this task is to swap each of the
** string’s characters, two by two.
*/

void my_swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_evil_str(char *str)
{
    int nbr = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++){
        nbr = i;
    }
    while (nbr >= k){
        my_swap_char(&str[k], &str[nbr]);
        nbr--;
        k++;
    }
    return str;
}
