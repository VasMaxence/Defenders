/*
** EPITECH PROJECT, 2019
** graph
** File description:
** data_shop.c
*/

#include "my_defenders.h"

void set_nb_skill(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp < 0)
        return;
    getline(&line, &len, fp);
    game->data.skill = my_getnbr(line);
    free(line);
    fclose(fp);
}

void set_position_text_shop(s_defenders *game)
{
    int j = 13;

    for (int i = 0; i < 24; i++) {
        game->shop.text[i].pos.x = game->shop.draw[j].pos.x
        + (15 * game->data.scale_img.x);
        game->shop.text[i].pos.y = game->shop.draw[j].pos.y
        + (2 * game->data.scale_img.y);
        j += 2;
        sfText_setPosition(game->shop.text[i].text,
        game->shop.text[i].pos);
    }
    game->shop.text[24].pos.x = game->shop.draw[5].pos.x
    + (15 * game->data.scale_img.x);
    game->shop.text[24].pos.y = game->shop.draw[5].pos.y
    - (24 * game->data.scale_img.y);
    sfText_setPosition(game->shop.text[24].text,
    game->shop.text[24].pos);
}

void set_text_shop(s_defenders *game)
{
    for (int i = 0; i < 25; i++) {
        game->shop.text[i].text = sfText_create();
        if (i < 24) {
            sfText_setString(game->shop.text[i].text,
            my_nb_to_str(game->shop.stats.level[i]));
            sfText_setCharacterSize(game->shop.text[i].text, 35);
        } else {
            sfText_setString(game->shop.text[i].text,
            my_nb_to_str(game->data.skill));
            sfText_setCharacterSize(game->shop.text[i].text, 80);
        }
        sfText_setFont(game->shop.text[i].text, game->data.font);
        sfText_setColor(game->shop.text[i].text, sfWhite);
        sfText_setScale(game->shop.text[i].text, game->data.scale_img);
    }
    set_position_text_shop(game);
}
