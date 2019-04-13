/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** arg2.c
*/

#include "include/my.h"
#include <stdarg.h>

void arg_nbr_unsigned(va_list args)
{
    nbr_unsigned(va_arg(args, unsigned int));
}

void arg_my_put_nbr_print(va_list args)
{
    my_put_nbr_print(va_arg(args, int));
}
