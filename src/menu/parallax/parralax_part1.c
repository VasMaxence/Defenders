/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/parallax/parralax_part1.c
*/

#include "my_defenders.h"

void parralax_two(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[1]);
    int width_img = sfTexture_getSize(game->menu.draw[2].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 60) {
        if (game->menu.draw[2].pos.x < game->menu.draw[3].pos.x) {
            game->menu.draw[2].pos.x -= 1;
            game->menu.draw[3].pos.x = game->menu.draw[2].pos.x + width_img;
        } else {
            game->menu.draw[3].pos.x -= 1;
            game->menu.draw[2].pos.x = game->menu.draw[3].pos.x + width_img;
        }
        if (game->menu.draw[2].pos.x <= -(width_img)) {
            game->menu.draw[2].pos.x = game->menu.draw[3].pos.x + (width_img);
        } else if (game->menu.draw[3].pos.x <= -(width_img)) {
            game->menu.draw[3].pos.x = game->menu.draw[2].pos.x + (width_img);
        }
        fix_pos_two(game);
    }
}

void fix_pos_two(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[2].sprite, game->menu.draw[2].pos);
    sfSprite_setPosition(game->menu.draw[3].sprite, game->menu.draw[3].pos);
    sfClock_restart(game->menu.clock[1]);
}

void parralax_three(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[2]);
    int width_img = sfTexture_getSize(game->menu.draw[4].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 45) {
        if (game->menu.draw[4].pos.x < game->menu.draw[5].pos.x) {
            game->menu.draw[4].pos.x -= 1;
            game->menu.draw[5].pos.x = game->menu.draw[4].pos.x + width_img;
        } else {
            game->menu.draw[5].pos.x -= 1;
            game->menu.draw[4].pos.x = game->menu.draw[5].pos.x + width_img;
        }
        if (game->menu.draw[4].pos.x <= -(width_img)) {
            game->menu.draw[4].pos.x = game->menu.draw[5].pos.x + (width_img);
        } else if (game->menu.draw[5].pos.x <= -(width_img)) {
            game->menu.draw[5].pos.x = game->menu.draw[4].pos.x + (width_img);
        }
        fix_pos_three(game);
    }
}

void fix_pos_three(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[4].sprite, game->menu.draw[4].pos);
    sfSprite_setPosition(game->menu.draw[5].sprite, game->menu.draw[5].pos);
    sfClock_restart(game->menu.clock[2]);
}
