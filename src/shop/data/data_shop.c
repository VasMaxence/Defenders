/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/shop/data/data_shop.c
*/

#include "my_defenders.h"

char *take_nbr(char *str)
{
    char *ret = malloc(sizeof(char) * 2);
    int i = -1;

    while (str[++i])
        if (str[i] >= '0' && str[i] <= '9')
            ret[0] = str[i];
    ret[1] = '\0';
    return (ret);
}

void set_skill_level(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 24; i++) {
        getline(&line, &len, fp);
        game->shop.stats.level[i] = my_getnbr(take_nbr(line));
    }
    free(line);
    fclose(fp);
}

void set_texture_shop(s_defenders *game)
{
    FILE *fp = fopen("config/shop/img.fpc", "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 60; i++) {
        getline(&line, &len, fp);
        line[my_strlen(line) - 1] = '\0';
        game->shop.draw[i].sprite = sfSprite_create();
        game->shop.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->shop.draw[i].sprite,
        game->shop.draw[i].texture, sfTrue);
        sfSprite_setScale(game->shop.draw[i].sprite, game->data.scale_img);
    }
    free(line);
    fclose(fp);
}

void set_pos_texture_shop(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);

    pos_window_shop(game, size_window);
    for (int i = 0; i < 60; i++)
        sfSprite_setPosition(game->shop.draw[i].sprite, game->shop.draw[i].pos);
}

int set_data_shop(s_defenders *game)
{
    set_texture_shop(game);
    set_pos_texture_shop(game);
    return (1);
}
