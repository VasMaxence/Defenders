/*
** EPITECH PROJECT, 2018
** MY_STRNCPY
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int nb_carac;

    nb_carac = my_strl(src);
    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > nb_carac)
        dest[i] = '\0';
    return (dest);
}
