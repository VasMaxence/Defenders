/*
** EPITECH PROJECT, 2018
** MY_STRLOWCASE
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;
    int j = 0;
    int nb_carac;

    nb_carac = my_strl(str);
    while (j < nb_carac) {
        if (str[i] <= 90 && str[i] >= 65)
            str[i] = str[(i + 32)];
        i++;
        j++;
    }
    return (str);
}
