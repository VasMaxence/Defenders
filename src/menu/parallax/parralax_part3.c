/*
** EPITECH PROJECT, 2019
** graph
** File description:
** parralax_part3.c
*/

#include "my_defenders.h"

void parralax_six(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[5]);
    int width_img = sfTexture_getSize(game->menu.draw[10].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 35) {
        if (game->menu.draw[10].pos.x < game->menu.draw[11].pos.x) {
            game->menu.draw[10].pos.x -= 2;
            game->menu.draw[11].pos.x = game->menu.draw[10].pos.x + width_img;
        } else {
            game->menu.draw[11].pos.x -= 2;
            game->menu.draw[10].pos.x = game->menu.draw[11].pos.x + width_img;
        }
        if (game->menu.draw[10].pos.x <= -(width_img)) {
            game->menu.draw[10].pos.x = game->menu.draw[11].pos.x + (width_img);
        } else if (game->menu.draw[11].pos.x <= -(width_img)) {
            game->menu.draw[11].pos.x = game->menu.draw[10].pos.x + (width_img);
        }
        fix_pos_six(game);
    }
}

void fix_pos_six(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[10].sprite, game->menu.draw[10].pos);
    sfSprite_setPosition(game->menu.draw[11].sprite, game->menu.draw[11].pos);
    sfClock_restart(game->menu.clock[5]);
}

void parralax_seven(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[6]);
    int width_img = sfTexture_getSize(game->menu.draw[12].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 20) {
        if (game->menu.draw[12].pos.x < game->menu.draw[13].pos.x) {
            game->menu.draw[12].pos.x -= 2;
            game->menu.draw[13].pos.x = game->menu.draw[12].pos.x + width_img;
        } else {
            game->menu.draw[13].pos.x -= 2;
            game->menu.draw[12].pos.x = game->menu.draw[13].pos.x + width_img;
        }
        if (game->menu.draw[12].pos.x <= -(width_img)) {
            game->menu.draw[12].pos.x = game->menu.draw[13].pos.x + (width_img);
        } else if (game->menu.draw[13].pos.x <= -(width_img)) {
            game->menu.draw[13].pos.x = game->menu.draw[12].pos.x + (width_img);
        }
        fix_pos_seven(game);
    }
}

void fix_pos_seven(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[12].sprite, game->menu.draw[12].pos);
    sfSprite_setPosition(game->menu.draw[13].sprite, game->menu.draw[13].pos);
    sfClock_restart(game->menu.clock[6]);
}
