/*
** EPITECH PROJECT, 2018
** MY_STRUPCASE
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;
    int j = 0;
    int nb_carac;

    nb_carac = my_strl(str);
    while (j < nb_carac) {
        if (str[i] <= 122 && str[i] >= 97)
            str[i] = str[(i - 32)];
        i++;
        j++;
    }
    return (str);
}
