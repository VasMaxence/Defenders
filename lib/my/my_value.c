/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_value.c
*/

#include "my.h"

int set_nb(char const *str, int nb, int i)
{
    while (str[i] <= '9' && str[i] >= '0') {
        nb *= 10;
        nb += str[i] - '0';
        i++;
    }
}

int my_value(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] < '0' && str[i] > '9')
            i++;
            nb = set_nb(str, nb, i);
            i++;
        }
        return (nb);
}
