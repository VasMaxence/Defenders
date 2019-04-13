/*
** EPITECH PROJECT, 2018
** MY_FIND_PRIME_SUP
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i;

    i = nb;
    while (i < 2147483648 && i > -2147482349) {
        if (my_is_prime(i))
            return (i);
        i++;
    }
}
