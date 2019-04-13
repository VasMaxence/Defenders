/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** draw_mob.c
*/

#include "my_defenders.h"

void up_anim(s_monster *tmp, s_defenders *game)
{
    sfVector2u size_img = get_size_img(tmp->draw.texture, game->data.scale_img);
    sfVector2f size_left = {0};

    if (tmp->type == 1)
        size_left.x = size_img.x / 9;
    else
        size_left.x = size_img.x / 10;
    tmp->rect.left += size_left.x;
    if (tmp->rect.left >= size_img.x - size_left.x)
        tmp->rect.left = 0;
    sfSprite_setTextureRect(tmp->draw.sprite, tmp->rect);
}

void check_anim(s_monster *tmp, s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(tmp->anim);

    if (timer.microseconds / 1000 > 200 / tmp->speed) {
        up_anim(tmp, game);
        sfClock_restart(tmp->anim);
    }
}

void check_moove_mob(s_monster *tmp, s_defenders *game, int x)
{
    if (tmp->draw.pos.x < (670 * game->data.scale_img.x))
        tmp->draw.pos.x += 2;
    else if (tmp->draw.pos.x >= (670 * game->data.scale_img.x)
    && tmp->draw.pos.x < (1200 + (x % 25)) * game->data.scale_img.x
    && tmp->draw.pos.y > 100 * game->data.scale_img.y)
        tmp->draw.pos.y -= 2;
    else if (tmp->draw.pos.x < (1450 + (x % 25)) * game->data.scale_img.x
    && tmp->draw.pos.y <= (100 * game->data.scale_img.y))
        tmp->draw.pos.x += 2;
    if (tmp->draw.pos.x >= 1450 * game->data.scale_img.x && tmp->draw.pos.y
    < (750 + (x % 20) * game->data.scale_img.y))
        tmp->draw.pos.y += 2;
    else if (tmp->draw.pos.y >= 750 * game->data.scale_img.x)
        tmp->draw.pos.x += 2;
}

void draw_mob(s_monster **wave, s_defenders *game)
{
    s_monster *tmp;
    sfTime timer;

    tmp = *wave;
    while (tmp && tmp->next)
        tmp = tmp->next;
    while (tmp) {
        timer = sfClock_getElapsedTime(tmp->clock);
        check_anim(tmp, game);
        if (timer.microseconds / 1000 > 70 / tmp->speed) {
            check_moove_mob(tmp, game, rand());
            sfSprite_setPosition(tmp->draw.sprite, tmp->draw.pos);
            sfClock_restart(tmp->clock);
        }
        sfRenderWindow_drawSprite(game->window, tmp->draw.sprite, NULL);
        tmp = tmp->prev;
    }
}
