/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/game/pause/event/event_pause_button.c
*/

#include "my_defenders.h"
#include "../include/ptr_button_pause.h"

void check_event_button_pause(s_defenders *game, sfEvent *event)
{
    ptr_button_pause ptr_pause;
    int j = -1;
    sfIntRect hitbox = {0, 0, 0, 0};

    ptr_pause.arg = 0;
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 1; i < 4; i++) {
            hitbox = set_rect_from_sprite(game->pause.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y))
                ptr_pause.arg = i;
        }
        while (PTR_BUTTON_PAUSE[++j].arg)
            if (PTR_BUTTON_PAUSE[j].arg == ptr_pause.arg)
                PTR_BUTTON_PAUSE[j].ptr(game, event);
    }
}

void resume_game(s_defenders *game, sfEvent *event)
{
    game->pause.bool = 0;
}

void return_menu_from_pause(s_defenders *game, sfEvent *event)
{
    game->pause.bool = 0;
    game->play.bool = 0;
    game->play.bool_menu = 1;
}
