/*
** EPITECH PROJECT, 2018
** MY_STR_ISALPHA
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    int nb_carac;
    int j = 0;

    nb_carac = my_strl(str);
    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65)
            j++;
        if (str[i] <= 122 && str[i] >= 97)
            j++;
        i++;
    }
    if (j == nb_carac)
        return (1);
    else
        return (0);
}
