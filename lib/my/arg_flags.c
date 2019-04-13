/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** arg_flag;c
*/

#include "include/my.h"
#include <stdarg.h>

void arg_binary(va_list args)
{
    binary(va_arg(args, int));
}

void arg_hexadecimal_maj(va_list args)
{
    hexadecimal_maj(va_arg(args, int));
}

void arg_hexadecimal_min(va_list args)
{
    hexadecimal_min(va_arg(args, int));
}

void arg_purcent(va_list args)
{
    purcent(va_arg(args, int));
}

void arg_putchar(va_list args)
{
    my_putchar_print(va_arg(args, int));
}
