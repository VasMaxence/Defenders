/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_flags3.c
*/

#include <stdarg.h>
#include "include/my.h"

int calcul_nbr_long_unsigned(unsigned int nb);

int calcul_nbr_long_unsigned(unsigned int nb)
{
    int i = 0;

    while (nb) {
        ++i;
        nb /= 10;
    }
    return (i);
}

int nbr_unsigned(unsigned int nb)
{
    int temp;
    int i;
    int j;

    if (nb == 0)
        my_putchar('0');
    i = calcul_nbr_long_unsigned(nb);
    while (i--) {
            j = i;
        temp = nb;
        while (j--)
            temp /= 10;
        my_putchar(temp % 10 + '0');
    }
    return (0);
}
