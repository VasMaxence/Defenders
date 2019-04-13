/*
** EPITECH PROJECT, 2018
** MY_IS_PRIME
** File description:
** made by MAXENCE.V
*/

int my_is_prime(int nb)
{
    int i;

    for (i = 2; i <= (nb / 2); i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
