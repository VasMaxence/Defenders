/*
** EPITECH PROJECT, 2018
** MY_STRCAPITALIZE
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int nb_carac;
    int i = 0;

    nb_carac = my_strl(str);
    while (i < nb_carac) {
        if (str[i] <= 90 && str[i] >= 65) {
            if (str[(i - 1)] != ' ')
                str[i] = str[(i + 32)];
        }
        if (str[i] <= 122 && str[i] >= 97) {
            if (str[(i - 1)] == ' ')
                str[i] = str [(i - 32)];
        }
    }
    return (str);
}
