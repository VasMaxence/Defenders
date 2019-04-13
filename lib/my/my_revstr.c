/*
** EPITECH PROJECT, 2018
** MY_REVSTR
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_revstr(char *str)
{
    char arr_temp;
    int i = 0;
    int nb_carac;

    nb_carac = my_strl(str) - 1;
    while (i < nb_carac) {
        arr_temp = str[i];
        str[i] = str[nb_carac];
        str[nb_carac] = arr_temp;
        i++;
        nb_carac--;
    }
    return (str);
}
