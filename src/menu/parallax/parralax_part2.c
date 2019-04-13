/*
** EPITECH PROJECT, 2019
** graph
** File description:
** parralax_part2.c
*/

#include "my_defenders.h"

void parralax_four(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[3]);
    int width_img = sfTexture_getSize(game->menu.draw[6].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 30) {
        if (game->menu.draw[6].pos.x < game->menu.draw[7].pos.x) {
            game->menu.draw[6].pos.x -= 1;
            game->menu.draw[7].pos.x = game->menu.draw[6].pos.x + width_img;
        } else {
            game->menu.draw[7].pos.x -= 1;
            game->menu.draw[6].pos.x = game->menu.draw[7].pos.x + width_img;
        }
        if (game->menu.draw[6].pos.x <= -(width_img)) {
            game->menu.draw[6].pos.x = game->menu.draw[7].pos.x + (width_img);
        } else if (game->menu.draw[7].pos.x <= -(width_img)) {
            game->menu.draw[7].pos.x = game->menu.draw[6].pos.x + (width_img);
        }
        fix_pos_four(game);
    }
}

void fix_pos_four(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[6].sprite, game->menu.draw[6].pos);
    sfSprite_setPosition(game->menu.draw[7].sprite, game->menu.draw[7].pos);
    sfClock_restart(game->menu.clock[3]);
}

void parralax_five(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[4]);
    int width_img = sfTexture_getSize(game->menu.draw[8].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 45) {
        if (game->menu.draw[8].pos.x < game->menu.draw[9].pos.x) {
            game->menu.draw[8].pos.x -= 2;
            game->menu.draw[9].pos.x = game->menu.draw[8].pos.x + width_img;
        } else {
            game->menu.draw[9].pos.x -= 2;
            game->menu.draw[8].pos.x = game->menu.draw[9].pos.x + width_img;
        }
        if (game->menu.draw[8].pos.x <= -(width_img)) {
            game->menu.draw[8].pos.x = game->menu.draw[9].pos.x + (width_img);
        } else if (game->menu.draw[9].pos.x <= -(width_img)) {
            game->menu.draw[9].pos.x = game->menu.draw[8].pos.x + (width_img);
        }
        fix_pos_five(game);
    }
}

void fix_pos_five(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[8].sprite, game->menu.draw[8].pos);
    sfSprite_setPosition(game->menu.draw[9].sprite, game->menu.draw[9].pos);
    sfClock_restart(game->menu.clock[4]);
}
