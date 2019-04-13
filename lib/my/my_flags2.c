/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_flags2.c
*/

#include "include/my.h"
#include <stdarg.h>

int adress(unsigned long adress)
{
    char const *base = "0123456789abcdef";
    char result[12];
    int i = 11;
    int a = 0;

    while (i == 11 || (adress / 16) > 0) {
        a = adress % 16;
        adress = adress / 16;
        result[i] = base[a];
        i--;
    }
    a  = adress % 16;
    result[i] = base[a];
    my_putstr("0x");
    my_putstr(result);
    return (1);
}

int octal(int nb)
{
    char const *base = "01234567";
    int div = 0;
    int mod = 0;

    if (nb < 0)
        return (84);
    mod = nb % my_strlen(base);
    div = nb / my_strlen(base);
    if (div > 0)
        octal(div);
    my_putchar(base[mod]);
    return (1);
}

int non_printable(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putstr("\\");
            octal(str[i]);
        } else
            my_putchar(str[i]);
        i++;
    }
}

int my_putstr_print(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar (str[i]);
        i++;
    }
}
