/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_nb_to_str.c
*/

#include "my.h"
#include <string.h>

char *my_nb_to_str(int nb)
{
    char *result = malloc(sizeof(char) * 11 + 1);
    int i = 0;

    if (nb < 0) {
        result[0] = '-';
        nb *= -1;
        i++;
    }
    if (nb == 0) {
        result[0] = '0';
        i++;
    }
    while (nb > 0) {
        result[i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    result[i] = '\0';
    result = my_revstr(result);
    return (result);
}

char *set_ret(char *result, int i)
{
    result[i] = '\0';
    result = my_revstr(result);
    result[i] = '\n';
    result[++i] = '\0';
    return (result);
}

char *my_nb_to_str_set(int nb)
{
    char *result = malloc(sizeof(char) * 11 + 2);
    int i = 0;

    if (nb < 0) {
        result[0] = '-';
        nb *= -1;
        i++;
    }
    if (nb == 0) {
        result[0] = '0';
        i++;
    }
    while (nb > 0) {
        result[i] = nb % 10 + '0';
        nb = nb / 10;
        i++;
    }
    result = set_ret(result, i);
    return (result);
}
