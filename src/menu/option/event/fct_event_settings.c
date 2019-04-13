/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/event/event_settings.c
*/

#include "my_defenders.h"

void up_music(s_defenders *game, sfEvent *event)
{
    if (game->data.volume_music < 100) {
        game->data.volume_music += 5;
        game->data.scale_bar_music.x = (float)game->data.volume_music / 100
        * game->data.scale_img.x;
        game->data.boolean.value_music = 1;
        sfMusic_setVolume(game->menu.music, game->data.volume_music);
        sfSprite_setScale(game->settings.draw[7].sprite,
        game->data.scale_bar_music);
    }
}

void down_music(s_defenders *game, sfEvent *event)
{
    if (game->data.volume_music > 0) {
        game->data.volume_music -= 5;
        game->data.scale_bar_music.x = (float)game->data.volume_music / 100 *
        game->data.scale_img.x;
        game->data.boolean.value_effect = 1;
        sfMusic_setVolume(game->menu.music, game->data.volume_music);
        sfSprite_setScale(game->settings.draw[7].sprite,
        game->data.scale_bar_music);
    }
}

void up_effect(s_defenders *game, sfEvent *event)
{
    if (game->data.volume_effect < 100) {
        game->data.volume_effect += 5;
        game->data.scale_bar_effect.x = (float)game->data.volume_effect / 100;
        sfSprite_setScale(game->settings.draw[13].sprite,
        game->data.scale_bar_effect);
    }
}

void down_effect(s_defenders *game, sfEvent *event)
{
    if (game->data.volume_effect > 0) {
        game->data.volume_effect -= 5;
        game->data.scale_bar_effect.x = (float)game->data.volume_effect / 100;
        sfSprite_setScale(game->settings.draw[13].sprite,
        game->data.scale_bar_effect);
    }
}

void play_and_stop_music(s_defenders *game, sfEvent *event)
{
    if (game->data.boolean.value_music) {
        game->data.boolean.value_music = 0;
        game->data.volume_music = 0;
        game->data.scale_bar_music.x = (float)game->data.volume_music / 100;
        sfMusic_setVolume(game->menu.music, game->data.volume_music);
        sfSprite_setScale(game->settings.draw[7].sprite,
        game->data.scale_bar_music);
    } else {
        game->data.boolean.value_music = 1;
        game->data.volume_music = 25;
        game->data.scale_bar_music.x = (float)game->data.volume_music / 100;
        sfMusic_setVolume(game->menu.music, game->data.volume_music);
        sfSprite_setScale(game->settings.draw[7].sprite,
        game->data.scale_bar_music);
    }
}
