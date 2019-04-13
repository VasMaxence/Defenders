/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** made by MAXENCE.V : 10/10/2018
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
