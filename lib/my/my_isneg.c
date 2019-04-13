/*
** EPITECH PROJECT, 2018
** MY_ISNEG
** File description:
** made by MAXENCE.V
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
