/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_flags3.c
*/

#include <stdarg.h>
#include "include/my.h"

int calcul_nbr_long(int nb);

int my_abs(int nb);

int calcul_nbr_long(int nb)
{
    int i = 0;

    while (nb) {
        ++i;
        nb /= 10;
    }
    return (i);
}

int my_abs(int nb)
{
    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        return (nb * -1);
    }
    return (nb);
}

int my_put_nbr_print(int nb)
{
    int temp;
    int i;
    int j;

    if (nb == -2147483648) {
        my_putstr("-2");
        nb = 147483648;
    }
    nb = my_abs(nb);
    i = calcul_nbr_long(nb);
    while (i--) {
        j = i;
        temp = nb;
        while (j--)
            temp /= 10;
        my_putchar(temp % 10 + '0');
    }
    return (0);
}
