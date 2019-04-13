/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_attack.c
*/

#include "my_defenders.h"

void draw_attack_tower(s_defenders *game)
{
    sfTime timer;
    sfVector2u size_img = get_size_img(game->defense.tower[0].animated.texture,
    game->data.scale_img);

    for (int i = 0; i < 4; i++) {
        if (game->defense.tower[i].shoot_bool) {
            timer = sfClock_getElapsedTime(game->defense.tower[i].clock);
            if (timer.microseconds / 1000 >
            game->defense.tower[i].attack_speed / 4) {
                game->defense.tower[i].hit_animate.left += size_img.x / 2;
                sfSprite_setTextureRect(game->defense.tower[i].animated.sprite,
                game->defense.tower[i].hit_animate);
                sfClock_restart(game->defense.tower[i].clock);
            }
            if (game->defense.tower[i].hit_animate.left >= size_img.x)
                game->defense.tower[i].shoot_bool = 0;
            sfRenderWindow_drawSprite(game->window,
            game->defense.tower[i].animated.sprite, NULL);
        }
    }
}
