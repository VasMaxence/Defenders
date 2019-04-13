/*
** EPITECH PROJECT, 2019
** graph
** File description:
** data_tilemapping.c
*/

#include "my_defenders.h"

void print_line_tilemapping(char *line_map, sfVector2f pos, s_defenders *game)
{
    int j = -1;
    int nb_carac = my_strlen(line_map);
    char *str = malloc(sizeof(char) * 4);

    for (int i = 0; i < nb_carac; i++) {
        j = -1;
        while (line_map[i] && line_map[i] != ';') {
            str[++j] = line_map[i++];
        }
        str[++j] = '\0';
        sfSprite_setPosition(game->tileset[my_getnbr(str)].sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->tileset[my_getnbr(str)].sprite, NULL);
        pos.x += (128 * game->data.scale_img.x);
    }
    free(str);
}

char **set_map_tilemapping(char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    char **ret = malloc(sizeof(char *) * nb_line_on_map(path));
    int i = -1;

    while (getline(&line, &len, fp) != -1) {
        ret[++i] = my_strdup(line);
    }
    ret[++i] = NULL;
    return (ret);
}

int value_tile(int y, int *x, char **map)
{
    char *ret = malloc(sizeof(char) * 4);
    int j = -1;

    while (map[y][++(*x)] && map[y][(*x)] != ';' && map[y][*x] != '\n') {
        ret[++j] = map[y][*x];
    }
    ret[++j] = '\0';
    return (my_getnbr(ret));
}

int **set_map_spawn_tilemapping(s_defenders *game, char *path)
{
    int **ret = malloc(sizeof(int *) * nb_line_on_map(path));
    int x = -1;
    int y = -1;
    int j = -1;

    while (game->play.tilemapping.map[++y]) {
        x = -1;
        j = -1;
        ret[y] =
        malloc(sizeof(int) * (my_strlen(game->play.tilemapping.map[y])));
        while (game->play.tilemapping.map[y][++x] != '\n'
        && game->play.tilemapping.map[y][x]) {
            ret[y][++j] = value_tile(y, &x,
            game->play.tilemapping.map);
        }
    }
}

void set_tilemapping(s_defenders *game, char *path)
{
    game->play.tilemapping.map = set_map_tilemapping(path);
    game->play.tilemapping.map_sp = set_map_spawn_tilemapping(game, path);
}
