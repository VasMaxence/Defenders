/*
** EPITECH PROJECT, 2018
** MY_PUT_NBR
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int calcul_nbr(int nb)
{
    int i = 0;

    while (nb) {
        i++;
        nb = nb / 10;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    int i;
    int l;
    int k;

    nb = null(nb);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    i = calcul_nbr(nb);
    while (i--) {
        k = i;
        l = nb;
        while (k--)
            l = l / 10;
        my_putchar(l % 10 + '0');
    }
    return (0);
}

int null(int nb)
{
    if (nb == 0) {
        my_putchar('0');
    }
    if ( nb == -2147483648){
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb == 2147483648) {
        my_putchar('2');
        nb = 147483648;
    }
    return (nb);
}
