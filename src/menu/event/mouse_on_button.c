/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/event/mouse_on_button.c
*/

#include "../../include/my_defenders.h"

sfIntRect set_rect_from_sprite(s_sprite draw, sfVector2f scale)
{
    sfIntRect res = {0, 0, 0, 0};
    sfVector2u size_img = sfTexture_getSize(draw.texture);

    res.top = draw.pos.y;
    res.left = draw.pos.x;
    res.width = size_img.x * scale.x;
    res.height = size_img.y * scale.y;
    return (res);
}

void mouse_pos_on_button(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0, 0, 0, 0};

    if (event->type == sfEvtMouseMoved)
        for (int i = 14; i < 18; i++) {
            hitbox = set_rect_from_sprite(game->menu.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseMove.x,
            event->mouseMove.y) == sfTrue) {
                sfSprite_setTexture(game->menu.draw[i].sprite,
                game->menu.draw[i + 4].texture, sfTrue);
                game->menu.button_value = i;
            } else {
                sfSprite_setTexture(game->menu.draw[i].sprite,
                game->menu.draw[i].texture, sfTrue);
            }
        }
}

void choose_button_with_keypad(s_defenders *game, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        for (int i = 14; i < 18; i++)
            sfSprite_setTexture(game->menu.draw[i].sprite,
                game->menu.draw[i].texture, sfTrue);
        if (event->key.code == sfKeyRight) {
            game->menu.button_value += 1;
        }
        else if (event->key.code == sfKeyLeft)
            game->menu.button_value -= 1;
        if (game->menu.button_value <= 14)
            game->menu.button_value = 14;
        else if (game->menu.button_value >= 17)
            game->menu.button_value = 17;
        sfSprite_setTexture(game->menu.draw[game->menu.button_value].sprite,
        game->menu.draw[game->menu.button_value + 4].texture, sfTrue);
    }
}
