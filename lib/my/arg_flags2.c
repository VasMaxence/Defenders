/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** arg2.c
*/

#include "include/my.h"
#include <stdarg.h>

void arg_adress(va_list args)
{
    adress(va_arg(args, unsigned long));
}

void arg_octal(va_list args)
{
    octal(va_arg(args, int));
}

void arg_non_printable(va_list args)
{
    non_printable(va_arg(args, char *));
}

void arg_my_putstr_print(va_list args)
{
    my_putstr_print(va_arg(args, char *));
}
