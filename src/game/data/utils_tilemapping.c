/*
** EPITECH PROJECT, 2019
** graph
** File description:
** utils_tilemapping.c
*/

#include "my_defenders.h"

char *my_strdup(char *str)
{
    char *ret = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = -1;

    while (str[++i])
        ret[i] = str[i];
    ret[i] = '\0';
    return (ret);
}

int nb_line_on_map(char *path)
{
    int count = 0;
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp < 0)
        return (0);
    while (getline(&line, &len, fp) != -1)
        count++;
    free(line);
    fclose(fp);
    return (count + 1);
}
