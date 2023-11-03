/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** Return a int raised to the power recursively
*/

int my_compute_power_rec(int nb, int power)
{
    if (power == 1) {
        return (nb);
    }
    if (power < 0) {
        return (0);
    }
    if (power == 0) {
        return (1);
    }
    return (my_compute_power_rec(nb, power - 1)* nb);
}
