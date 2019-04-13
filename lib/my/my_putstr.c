/*
** EPITECH PROJECT, 2018
** MY_PUTSTR
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
}
