/*
** EPITECH PROJECT, 2018
** MY_GETNBR
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 1;
    long int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            j *= -1;
            i++;
        }
    }
    while (str[i] < '0' && str[i] > '9')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = (nb + str[i] - '0');
        if (nb > 2147483648)
            return (0);
        i++;
    }
    return (nb * j);
}

int error(int nb, int j)
{
    if (nb == 2147483648 && j == 1)
        return (0);
}
