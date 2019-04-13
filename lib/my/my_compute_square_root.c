/*
** EPITECH PROJECT, 2018
** MY_COMPUTE_SQUARE_ROOT
** File description:
** made by MAXENCE.V
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 0)
        return (0);
    for (i = 1; i < (nb / 2); i++) {
        if ((i * i) == nb)
            return (i);
        if ((i * i) >= 46341)
            return (0);
    }
}
