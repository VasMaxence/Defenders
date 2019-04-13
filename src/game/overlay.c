/*
** EPITECH PROJECT, 2019
** graph
** File description:
** overlay.c
*/

#include "my_defenders.h"
#include "include/ptr_overlay.h"

void check_ptr_overlay(s_defenders *game, evt_overlay click_over)
{
    int j = -1;

    while (PTR_FUNC[++j].arg)
        if (PTR_FUNC[j].arg == click_over.arg)
            if (click_over.arg <= 3)
                PTR_FUNC[j].ptr(game, click_over.arg - 1);
            else if (click_over.arg > 6 && click_over.arg <= 10)
                PTR_FUNC[j].ptr(game, click_over.arg - 7);
}

void event_overlay(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0};
    evt_overlay click_over;

    click_over.arg = 0;
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 1; i < 15; i++) {
            hitbox = set_rect_from_sprite(game->play.overlay.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y) ==  sfTrue)
                click_over.arg = i;
        }
        check_ptr_overlay(game, click_over);
    }
}
