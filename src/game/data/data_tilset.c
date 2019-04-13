/*
** EPITECH PROJECT, 2019
** graph
** File description:
** data_tileset.c
*/

#include "my_defenders.h"

int nb_tile_in_tileset(char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    while (getline(&line, &len, fp) != -1)
        count++;
    free(line);
    fclose(fp);
    return (count++);
}

void set_data_tilset(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    int i = -1;
    sfVector2f size = game->data.scale_img;

    size.x /= 2;
    size.y /= 2;
    if (!path || fp < 0)
        return;
    game->tileset = malloc(sizeof(struct t_sprite) * nb_tile_in_tileset(path));
    while (getline(&line, &len, fp) != -1) {
        game->tileset[++i].sprite = sfSprite_create();
        line[my_strlen(line) - 1] = '\0';
        game->tileset[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->tileset[i].sprite,
        game->tileset[i].texture, sfTrue);
        if (i != 0)
            sfSprite_setScale(game->tileset[i].sprite, size);
    }
}
