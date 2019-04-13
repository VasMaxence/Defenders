/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** set_texture_monster.c
*/

#include "my_defenders.h"

void set_pos_and_rect_list(s_monster *tmp, s_defenders *game, int i)
{
    tmp->draw.pos.x = i;
    tmp->draw.pos.y = (500 * game->data.scale_img.y) + (rand() % 25);
    sfSprite_setPosition(tmp->draw.sprite, tmp->draw.pos);
    sfSprite_setScale(tmp->draw.sprite, game->data.scale_img);
    sfSprite_setTextureRect(tmp->draw.sprite, tmp->rect);
}

void set_rect_mob(s_monster **list, s_defenders *game)
{
    s_monster *tmp = *list;
    sfVector2u size_img = {0};
    int i = -10;

    while (tmp) {
        size_img = get_size_img(tmp->draw.texture, game->data.scale_img);
        tmp->rect.left = 0;
        tmp->rect.top = 0;
        if (tmp->type == 1)
            tmp->rect.width = size_img.x / 9;
        else
            tmp->rect.width = size_img.x / 10;
        tmp->rect.height = size_img.y;
        tmp->alive = 1;
        set_pos_and_rect_list(tmp, game, i);
        tmp->clock = sfClock_create();
        tmp = tmp->next;
        i -= 35 + (rand() % 40);
    }
}
