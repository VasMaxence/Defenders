/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/event/event_settings.c
*/

#include "my_defenders.h"
#include "../include/ptr_event_settings.h"

int event_settings_check(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0, 0, 0, 0};
    ptr_settings button;
    int j = -1;

    button.arg = 0;
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 6; i < 25; i++) {
            hitbox = set_rect_from_sprite(game->settings.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y) == sfTrue) {
                button.arg = i;
            }
        }
        while (PTR_BUTTON_SETTINGS[++j].arg) {
            if (PTR_BUTTON_SETTINGS[j].arg == button.arg)
                PTR_BUTTON_SETTINGS[j].ptr(game, event);
        }
    }
}

void close_settings(s_defenders *game, sfEvent *event)
{
    while (sfRenderWindow_isOpen(game->window) && game->settings.bool_set) {
        sfRenderWindow_clear(game->window, sfBlack);
        parralax_menu(game);
        draw_music_settings(game);
        sfRenderWindow_drawSprite(game->window, game->settings.alert.sprite,
        NULL);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event->type == sfEvtKeyPressed
            && event->key.code == sfKeyEscape || event->key.code == sfKeyReturn)
                game->settings.bool_set = 0;
        }
    }
}

void play_and_stop_effect(s_defenders *game, sfEvent *event)
{
    if (game->data.boolean.value_effect) {
        game->data.boolean.value_effect = 0;
        game->data.volume_effect = 0;
        game->data.scale_bar_effect.x = (float)game->data.volume_effect / 100;
        sfSprite_setScale(game->settings.draw[13].sprite,
        game->data.scale_bar_effect);
    } else {
        game->data.boolean.value_effect = 1;
        game->data.volume_effect = 25;
        game->data.scale_bar_effect.x = (float)game->data.volume_effect / 100;
        sfSprite_setScale(game->settings.draw[13].sprite,
        game->data.scale_bar_effect);
    }
}
