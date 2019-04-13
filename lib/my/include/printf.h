/*
** EPITECH PROJECT, 2018
** include
** File description:
** printf.h
*/

#ifndef _PRINTF_H_

#define _PRINTF_H_

#include <stdarg.h>
#include <string.h>

void arg_adress(va_list data);
void arg_octal(va_list data);
void arg_non_printable(va_list data);
void arg_my_putstr_print(va_list data);
void arg_my_put_nbr_print(va_list data);
void arg_nbr_unsigned(va_list data);
void arg_binary(va_list data);
void arg_hexadecimal_maj(va_list data);
void arg_hexadecimal_min(va_list data);
void arg_putchar(va_list data);
void arg_purcent(va_list data);

struct s_fct_printf
{
    char arg;
    void (*ptr)(va_list);
};

const struct s_fct_printf FCT_PRINT[] = {
    {'%', &arg_purcent},
    {'c', &arg_putchar},
    {'d', &arg_my_put_nbr_print},
    {'i', &arg_my_put_nbr_print},
    {'u', &arg_nbr_unsigned},
    {'x', &arg_hexadecimal_min},
    {'X', &arg_hexadecimal_maj},
    {'o', &arg_octal},
    {'b', &arg_binary},
    {'p', &arg_adress},
    {'s', &arg_my_putstr_print},
    {'S', &arg_non_printable},
    {'\0', NULL}};

#endif
