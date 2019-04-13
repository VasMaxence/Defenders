/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/data/data_pos_settings.c
*/

#include "my_defenders.h"

void set_pos_decor_settings(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);

    game->settings.draw[3].pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->settings.draw[3].pos.y = game->settings.draw[0].pos.y
    - (20 * game->data.scale_img.y);
    size_img =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);
    game->settings.draw[1].pos.x = (size_window.x / 2)
    - (size_img.x) - (25 * game->data.scale_img.x);
    game->settings.draw[1].pos.y = game->settings.draw[0].pos.y
    + (100 * game->data.scale_img.y);
    get_size_img(game->settings.draw[2].texture, game->data.scale_img);
    game->settings.draw[2].pos.x = (size_window.x / 2)
    + (10 * game->data.scale_img.x);
    game->settings.draw[2].pos.y = game->settings.draw[0].pos.y
    + (100 * game->data.scale_img.y);
}

void set_pos_rod_settings(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->settings.draw[4].texture, game->data.scale_img);
    sfVector2u size_bg =
    get_size_img(game->settings.draw[0].texture, game->data.scale_img);

    game->settings.draw[4].pos.x = (game->settings.draw[0].pos.x)
    + (50 * game->data.scale_img.x);
    game->settings.draw[4].pos.y = game->settings.draw[0].pos.y
    + (100 * game->data.scale_img.y) - size_img.y;
    game->settings.draw[5].pos.x = (game->settings.draw[0].pos.x + size_bg.x)
    - (100 * game->data.scale_img.x);;
    game->settings.draw[5].pos.y = game->settings.draw[0].pos.y
    + (100 * game->data.scale_img.y) - size_img.y;
}

void set_audio_pos2(s_defenders *game, sfVector2u size_img, sfVector2u size_bg)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_bgw =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);

    game->settings.draw[8].pos.x = game->settings.draw[6].pos.x
    - (size_img.x - (25 * game->data.scale_img.x));
    game->settings.draw[8].pos.y = game->settings.draw[6].pos.y;
    game->settings.draw[9].pos.x = game->settings.draw[6].pos.x
    + size_bg.x - (25 * game->data.scale_img.x);
    game->settings.draw[9].pos.y = game->settings.draw[6].pos.y;
    size_img =
    get_size_img(game->settings.draw[10].texture, game->data.scale_img);
    size_bg =
    get_size_img(game->settings.draw[9].texture, game->data.scale_img);
    game->settings.draw[10].pos.x = game->settings.draw[1].pos.x
    + (size_bgw.x / 2) - (size_img.x / 2);
    game->settings.draw[10].pos.y = game->settings.draw[9].pos.y
    + (size_bg.y + (10 * game->data.scale_img.y));
    game->settings.draw[11].pos = game->settings.draw[10].pos;
}

void set_music_audio(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->settings.draw[6].texture, game->data.scale_img);
    sfVector2u size_bg =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);

    game->settings.draw[6].pos.x = game->settings.draw[1].pos.x
    + ((size_bg.x - size_img.x) / 2);
    game->settings.draw[6].pos.y = game->settings.draw[1].pos.y
    + ((100 * game->data.scale_img.y));
    game->settings.draw[7].pos = game->settings.draw[6].pos;
    game->settings.draw[7].pos.x += (8 * game->data.scale_img.x);
    game->settings.draw[7].pos.y += (8 * game->data.scale_img.y);
    size_img =
    get_size_img(game->settings.draw[8].texture, game->data.scale_img);
    size_bg =
    get_size_img(game->settings.draw[6].texture, game->data.scale_img);
    set_audio_pos2(game, size_img, size_bg);
}

void set_settings_audio_pos(s_defenders *game, sfVector2u size_window)
{
    set_music_audio(game, size_window);
    set_effect_music(game, size_window);
    set_pos_text_audio(game, size_window);
    set_pos_graph_settings(game, size_window);
    set_pos_text_graph(game, size_window);
    for (int i = 0; i < 24; i++)
        sfSprite_setPosition(game->settings.draw[i].sprite,
        game->settings.draw[i].pos);
    for (int i = 0; i < 6; i++)
        sfText_setPosition(game->settings.text[i].text,
        game->settings.text[i].pos);
}
