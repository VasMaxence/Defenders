/*
** EPITECH PROJECT, 2018
** MY_STR_ISPRINTABLE
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;
    int nb_carac;
    int j = 0;

    nb_carac = my_strl(str);
    while (str[i] != '\0') {
        if (str[i] <= 126 && str[i] >= 32)
            j++;
        i++;
    }
    if (j == nb_carac)
        return (1);
    else
        return (0);
}
