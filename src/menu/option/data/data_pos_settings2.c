/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/data/data_pos_settings.c
*/

#include "my_defenders.h"

void set_effect_music(s_defenders *game, sfVector2u size_window)
{
    for (int i = 12; i < 18; i++) {
        game->settings.draw[i].pos.x = game->settings.draw[i - 6].pos.x;
        game->settings.draw[i].pos.y = game->settings.draw[i - 6].pos.y
        + (200 * game->data.scale_img.y);
    }
}

int set_pos_text_audio(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);

    game->settings.text[0].pos.x = game->settings.draw[1].pos.x
    + (size_img.x / 2) - (8 * 8 * game->data.scale_img.y);
    game->settings.text[0].pos.y = (game->settings.draw[6].pos.y)
    - (100 * game->data.scale_img.y);
    game->settings.text[1].pos.x = game->settings.draw[1].pos.x
    + (size_img.x / 2) - (10 * 8 * game->data.scale_img.y);
    game->settings.text[1].pos.y = game->settings.text[0].pos.y
    + (240 * game->data.scale_img.y);
}
