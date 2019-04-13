/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/game/pause/data/set_data_pause.c
*/

#include "my_defenders.h"

void set_data_pause(s_defenders *game)
{
    set_texture_pause(game, "config/pause/img.fpc");
    set_text_pause(game, "config/pause/text.fpc");
    set_pos_pause(game);
    set_text_pause_pos(game);
}

void set_equa_pause_button(s_defenders *game, sfVector2u size_window,
sfVector2u size_img, sfVector2u size_bg)
{
    game->pause.draw[0].pos.x = (size_window.x / 2)
    - ((size_bg.x / 2) * game->data.scale_img.x);
    game->pause.draw[0].pos.y = (size_window.y / 2)
    - ((size_bg.y / 2) * game->data.scale_img.y);
    game->pause.draw[1].pos.x = (size_window.x / 2)
    - (((size_img.x / 2) * game->data.scale_img.x) +
    (size_img.x * game->data.scale_img.x) + (25 * game->data.scale_img.x));
    game->pause.draw[1].pos.y = (size_window.y / 2)
    - ((size_img.y / 2) * game->data.scale_img.y);
}

void set_pos_pause(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img = sfTexture_getSize(game->pause.draw[1].texture);
    sfVector2u size_bg = sfTexture_getSize(game->pause.draw[0].texture);

    set_equa_pause_button(game, size_window, size_img, size_bg);
    size_img.x *= game->data.scale_img.x;
    size_img.y *= game->data.scale_img.y;
    size_bg.x *= game->data.scale_img.x;
    size_bg.y *= game->data.scale_img.x;
    for (int i = 2; i < 4; i++) {
        game->pause.draw[i].pos.x = game->pause.draw[i - 1].pos.x
        + (size_img.x + 25);
        game->pause.draw[i].pos.y = game->pause.draw[i - 1].pos.y;
    }
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(game->pause.draw[i].sprite,
        game->pause.draw[i].pos);
}

void set_text_pause(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 3; i++)
        game->pause.text[i].text = sfText_create();
    if (fp == NULL)
        return;
    for (int i = 0; i < 3; i++) {
        getline(&line, &len, fp);
        sfText_setString(game->pause.text[i].text, line);
        sfText_setCharacterSize(game->pause.text[i].text, 80);
        sfText_setColor(game->pause.text[i].text, sfBlack);
        sfText_setFont(game->pause.text[i].text, game->data.font);
        sfText_setScale(game->pause.text[i].text, game->data.scale_img);
    }
    free(line);
    fclose(fp);
}

void set_texture_pause(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line =  NULL;
    size_t len = 0;

    for (int i = 0; i < 4; i++) {
        if (getline(&line, &len, fp) == -1)
            return;
        line[my_strlen(line) - 1] = '\0';
        game->pause.draw[i].sprite = sfSprite_create();
        game->pause.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->pause.draw[i].sprite,
        game->pause.draw[i].texture, sfTrue);
        sfSprite_setScale(game->pause.draw[i].sprite, game->data.scale_img);
    }
    fclose(fp);
    free(line);
}
