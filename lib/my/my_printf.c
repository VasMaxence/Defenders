/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf.c
*/

#include "include/printf.h"
#include "include/my.h"
#include <stdarg.h>

void ptr_fct_print(int j, va_list data, struct s_fct_printf data_printf);

int my_printf(char *str, ...)
{
    int i = 0;
    int j;
    struct s_fct_printf data_printf;
    va_list data;

    va_start(data, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            j = 0;
            data_printf.arg = str[i];
            ptr_fct_print(j, data, data_printf);
            i++;
        } else if (str[i] != '%') {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(data);
}

void ptr_fct_print(int j, va_list data, struct s_fct_printf data_printf)
{
    while (FCT_PRINT[j].arg) {
        if (FCT_PRINT[j].arg == data_printf.arg)
            FCT_PRINT[j].ptr(data);
        j++;
    }
}
