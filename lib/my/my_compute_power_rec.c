/*
** EPITECH PROJECT, 2018
** MY_COMPUTE_POWER_REC
** File description:
** made by MAXENCE.V
*/

int my_compute_power_rec(int nb, int p)
{
    long int test;

    test = nb;
    if (p == 0)
        return (1);
    if (test > 2147483648 || test <= -2147483648)
        return (0);
    return (my_compute_power_rec(nb, p - 1) * nb);
}
