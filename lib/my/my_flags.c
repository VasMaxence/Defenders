/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_flags.h
*/

#include "include/my.h"
#include <stdarg.h>

int binary(int nb)
{
    char const *base = "01";
    int div = 0;
    int mod = 0;

    if (nb < 0) {
        my_putstr("-0b");
        nb *= -1;
    }
    mod = nb % my_strlen(base);
    div = nb / my_strlen(base);
    if (div > 0)
        binary(div);
    my_putchar(base[mod]);
    return (1);
}

int hexadecimal_maj(int nb)
{
    char const *base = "0123456789ABCDEF";
    int div = 0;
    int mod = 0;

    if (nb < 0)
        return (84);
    mod = nb % my_strlen(base);
    div = nb / my_strlen(base);
    if (div > 0)
        hexadecimal_maj(div);
    my_putchar(base[mod]);
    return (1);
}

int hexadecimal_min(int nb)
{
    char const *base = "0123456789abcdef";
    int div = 0;
    int mod = 0;

    if (nb < 0)
        return (84);
    mod = nb % my_strlen(base);
    div = nb / my_strlen(base);
    if (div > 0)
        hexadecimal_min(div);
    my_putchar(base[mod]);
    return (1);
}

int purcent(int nb)
{
    write(1, "%", 1);
}

void my_putchar_print(int c)
{
    write(1, &c, 1);
}
