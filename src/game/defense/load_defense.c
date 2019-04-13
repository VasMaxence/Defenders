/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** load_defense.c
*/

#include "my_defenders.h"

void pos_tower(char **map, s_defenders *game)
{
    sfVector2f pos = {0, 0};
    char str[2];

    for (int i = 0; map[i]; i++) {
        pos.x = 0;
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] != ' ' && map[i][j] != ';' && map[i][j] != '\n') {
                str[0] = map[i][j];
                str[1] = '\0';
                game->defense.tower[my_getnbr(str)].draw.pos = pos;
                sfSprite_setPosition(
                game->defense.tower[my_getnbr(str)].draw.sprite,
                game->defense.tower[my_getnbr(str)].draw.pos);
            }
            if (map[i][j] == ';')
                pos.x += (64 * game->data.scale_img.x);
        }
        pos.y += (64 * game->data.scale_img.y);
    }
}

void pos_archer(char **map, s_defenders *game)
{
    sfVector2f pos = {0, 0};
    char str[2];

    for (int i = 0; map[i]; i++) {
        pos.x = 0;
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] != ' ' && map[i][j] != ';' && map[i][j] != '\n') {
                str[0] = map[i][j];
                str[1] = '\0';
                game->defense.archer[my_getnbr(str)].draw.pos = pos;
                sfSprite_setPosition(
                game->defense.archer[my_getnbr(str)].draw.sprite,
                game->defense.archer[my_getnbr(str)].draw.pos);
            }
            if (map[i][j] == ';')
                pos.x += (64 * game->data.scale_img.x);
        }
        pos.y += (64 * game->data.scale_img.y);
    }
}

void set_pos_def2(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    char **map = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 10; i++) {
        getline(&line, &len, fp);
        map[i] = my_strdup(line);
    }
    map[10] = NULL;
    fclose(fp);
    free(line);
    pos_archer(map, game);
}

void set_pos_def(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    char **map = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 10; i++) {
        getline(&line, &len, fp);
        map[i] = my_strdup(line);
    }
    map[10] = NULL;
    fclose(fp);
    free(line);
    pos_tower(map, game);
}

void load_defense(s_defenders *game)
{
    set_data_archer(game);
    set_data_spell(game);
    set_data_tower(game);
    set_pos_def(game, "config/defense/map/tower.fpc");
    set_pos_def2(game, "config/defense/map/archer.fpc");
}
