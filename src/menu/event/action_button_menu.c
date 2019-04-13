/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/event/action_button_menu.c
*/

#include "my_defenders.h"
#include "../include/button_menu.h"

void event_of_button_menu(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0, 0, 0, 0};
    button_menu clicked;
    int j = -1;

    clicked.arg = 0;
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 14; i < 18; i++) {
            hitbox = set_rect_from_sprite(game->menu.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y) == sfTrue) {
                clicked.arg = i - 13;
            }
        }
        while (PTR_BUTTON[++j].arg) {
            if (PTR_BUTTON[j].arg == clicked.arg)
                PTR_BUTTON[j].ptr(game, event);
        }
    }
}

void event_of_enter_menu(s_defenders *game, sfEvent *event)
{
    button_menu clicked;
    int j = -1;

    clicked.arg = 0;
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn)
        clicked.arg = game->menu.button_value - 13;
    while (PTR_BUTTON[++j].arg) {
        if (PTR_BUTTON[j].arg == clicked.arg)
            PTR_BUTTON[j].ptr(game, event);
    }
}
