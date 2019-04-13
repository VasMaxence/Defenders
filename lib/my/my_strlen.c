/*
** EPITECH PROJECT, 2018
** MY_STRLEN
** File description:
** made by MAXENCE.V
*/

#include <string.h>

int my_strlen(char const *str)
{
    int n = 0;

    if (!str)
        return (0);
    while (str[n])
        n++;
    return (n);
}
