/*
** EPITECH PROJECT, 2018
** my
** File description:
** print_usage.c
*/

#include "include/my.h"

void print_usage(char *folder)
{
    FILE *fp = fopen(folder, "r");
    char *line_usage = NULL;
    size_t len = 0;

    while (getline(&line_usage, &len, fp) != -1)
        my_putstr(line_usage);
    free(line_usage);
    fclose(fp);
}
