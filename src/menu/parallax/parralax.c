/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/parallax.c
*/

#include "../../include/my_defenders.h"

void parralax_menu(s_defenders *game)
{
    parralax_one(game);
    parralax_two(game);
    parralax_three(game);
    parralax_four(game);
    parralax_five(game);
    parralax_six(game);
    parralax_seven(game);
    for (int i = 0; i < 14; i++)
        sfRenderWindow_drawSprite(game->window,
        game->menu.draw[i].sprite, NULL);
}

void parralax_one(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->menu.clock[0]);
    int width_img = sfTexture_getSize(game->menu.draw[0].texture).x
    * game->data.scale_img.x;

    if (timer.microseconds / 1000 > 100) {
        if (game->menu.draw[0].pos.x < game->menu.draw[1].pos.x) {
            game->menu.draw[0].pos.x -= 1;
            game->menu.draw[1].pos.x = game->menu.draw[0].pos.x + width_img;
        } else {
            game->menu.draw[1].pos.x -= 1;
            game->menu.draw[0].pos.x = game->menu.draw[1].pos.x + width_img;
        }
        if (game->menu.draw[0].pos.x <= -(width_img)) {
            game->menu.draw[0].pos.x = game->menu.draw[1].pos.x + (width_img);
        } else if (game->menu.draw[1].pos.x <= -(width_img)) {
            game->menu.draw[1].pos.x = game->menu.draw[0].pos.x + (width_img);
        }
        fix_pos_one(game);
    }
}

void fix_pos_one(s_defenders *game)
{
    sfSprite_setPosition(game->menu.draw[0].sprite, game->menu.draw[0].pos);
    sfSprite_setPosition(game->menu.draw[1].sprite, game->menu.draw[1].pos);
    sfClock_restart(game->menu.clock[0]);
}
