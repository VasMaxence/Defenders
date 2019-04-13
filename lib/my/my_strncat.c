/*
** EPITECH PROJECT, 2018
** MY_STRCAT
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j;

    j = my_strl(dest);
    while (src[i] != '\0' && i <= nb) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
