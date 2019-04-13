/*
** EPITECH PROJECT, 2018
** MY_STRCAT
** File description:
** made by MAXENCE.V
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = -1;
    int j = -1;
    char *result;

    result = malloc(my_strlen(dest) + my_strlen(src) + 1);
    if (dest)
        while (dest[++i])
            result[i] = dest[i];
    if (src)
        while (src[++j])
            result[i + j] = src[j];
    result[j + i] = '\0';
    return (result);
}
