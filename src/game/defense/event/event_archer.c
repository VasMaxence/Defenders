/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** event_archer.c
*/

#include "my_defenders.h"

sfIntRect set_hitbox_from_rect_archer(s_defenders *game, int i)
{
    sfIntRect ret = {0, 0, 0, 0};

    ret.width = sfTexture_getSize(game->defense.archer[i].draw.texture).x
    * (game->data.scale_img.x) / 3;
    ret.height = sfTexture_getSize(game->defense.archer[i].draw.texture).y
    * (game->data.scale_img.y);
    ret.left = game->defense.archer[i].draw.pos.x;
    ret.top = game->defense.archer[i].draw.pos.y;
    return (ret);
}

void up_archer(s_defenders *game, int i)
{
    sfVector2u size_img =
    sfTexture_getSize(game->defense.archer[i].draw.texture);

    if (game->defense.archer[i].hit_archer.left >= (size_img.x / 3) * 2
    || game->data.gold < 175) {
        return;
    } else {
        game->data.gold -= 175;
        game->defense.archer[i].hit_archer.left += (size_img.x / 3);
        game->defense.archer[i].damage += 10;
        game->defense.archer[i].range += 20;
        game->defense.archer[i].attack_speed -= 45;
        sfSprite_setTextureRect(game->defense.archer[i].draw.sprite,
        game->defense.archer[i].hit_archer);
    }
}

void event_archer(s_defenders *game, sfEvent *event, sfIntRect hitbox)
{
    for (int i = 0; i < 3; i++) {
        hitbox = set_hitbox_from_rect_archer(game, i);
        if (sfIntRect_contains(&hitbox, event->mouseButton.x,
        event->mouseButton.y) == sfTrue) {
            up_archer(game, i);
            return;
        }
    }
}
