/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/data/dara_menu.c
*/

#include "../../include/my_defenders.h"

void set_music_menu(s_defenders *game)
{
    game->menu.music =
    sfMusic_createFromFile("ressources/music/medieval_music.ogg");
    sfMusic_setLoop(game->menu.music, sfTrue);
    sfMusic_setVolume(game->menu.music, game->data.volume_music);
    game->data.scale_bar_music.x = (float)game->data.volume_music / 100;
    game->data.scale_bar_music.y = 1;
    game->data.scale_bar_effect.x = (float)game->data.volume_effect / 100;
    game->data.scale_bar_effect.y = 1;
    game->data.scale_bar_music.x *= game->data.scale_img.x;
    game->data.scale_bar_music.y *= game->data.scale_img.y;
    game->data.scale_bar_effect.x *= game->data.scale_img.x;
    game->data.scale_bar_effect.y *= game->data.scale_img.y;
    if (game->data.volume_music > 0)
        game->data.boolean.value_music = 1;
    else
        game->data.boolean.value_music = 0;
    if (game->data.volume_effect > 0)
        game->data.boolean.value_effect = 1;
    else
        game->data.boolean.value_effect = 0;
}

int set_img_menu(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return (1);
    for (int i = 0; i < 22; i++) {
        game->menu.draw[i].sprite = sfSprite_create();
        if (getline(&line, &len, fp) == -1)
            return (1);
        line[my_strlen(line) - 1] = '\0';
        game->menu.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->menu.draw[i].sprite,
            game->menu.draw[i].texture, sfTrue);
        sfSprite_setScale(game->menu.draw[i].sprite, game->data.scale_img);
    }
    fclose(fp);
    free(line);
    return (0);
}

void set_pos_menu_button(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img = {0, 0};

    size_img = sfTexture_getSize(game->menu.draw[14].texture);
    game->menu.draw[14].pos.x = (size_window.x / 2)
    - (size_img.x * 2 * game->data.scale_img.x) - 25;
    game->menu.draw[14].pos.y = (size_window.y / 2) - size_img.y / 2;
    for (int i = 15; i < 18; i++) {
        size_img = sfTexture_getSize(game->menu.draw[i].texture);
        game->menu.draw[i].pos.x = game->menu.draw[i - 1].pos.x
        + ((size_img.x + 25) * game->data.scale_img.x);
        game->menu.draw[i].pos.y = game->menu.draw[14].pos.y;
    }
}

void set_pos_menu(s_defenders *game)
{
    for (int i = 0; i < 14; i++) {
        game->menu.draw[i].pos.x = 0;
        if (i % 2)
            game->menu.draw[i].pos.x = 1920 * game->data.scale_img.x;
        game->menu.draw[i].pos.y = 0;
    }
    set_pos_menu_button(game);
    for (int i = 0; i < 18; i++) {
        sfSprite_setPosition(game->menu.draw[i].sprite,
        game->menu.draw[i].pos);
    }
}

int set_data_menu(s_defenders *game)
{
    game->menu.button_value = 14;
    if (set_img_menu(game, "config/menu/img_menu.fpc"))
        return (1);
    set_pos_menu(game);
    set_music_menu(game);
    game->menu.tuto.sprite = sfSprite_create();
    game->menu.tuto.texture =
    sfTexture_createFromFile("ressources/menu/skull.png", NULL);
    sfSprite_setTexture(game->menu.tuto.sprite,
    game->menu.tuto.texture, sfTrue);
    sfSprite_setScale(game->menu.tuto.sprite, game->data.scale_img);
}
