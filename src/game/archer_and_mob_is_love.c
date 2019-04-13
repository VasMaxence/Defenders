/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** archer_and_mob_is_love.c
*/

#include "my_defenders.h"

void archer_attack(s_monster *tmp, int i, s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->defense.tower[i].clock);

    if (timer.microseconds / 1000 > game->defense.tower[i].attack_speed * 5) {
        tmp->life -= game->defense.tower[i].damage;
        sfClock_restart(game->defense.tower[i].clock);
    }
}

sfIntRect set_range_archer(s_defenders *game, int i)
{
    sfIntRect ret = set_rect_from_sprite(game->defense.archer[i].draw,
    game->data.scale_img);

    ret.left -= game->defense.tower[i].range / 5;
    ret.width += (game->defense.tower[i].range) / 3;
    ret.top -= game->defense.tower[i].range / 5;
    ret.height += (game->defense.tower[i].range) / 3;
    return (ret);
}

void check_archer_vs_mob(s_defenders *game, s_monster **wave,
sfIntRect hitbox_archer, sfIntRect hitbox_mob)
{
    s_monster *tmp;

    for (int i = 0; i < 3; i++) {
        tmp = *wave;
        hitbox_archer = set_range_archer(game, i);
        while (tmp) {
            hitbox_mob = set_rect_from_sprite(tmp->draw, game->data.scale_img);
            if (sfIntRect_intersects(&hitbox_archer, &hitbox_mob, NULL)
            == sfTrue)
                archer_attack(tmp, i, game);
            tmp = tmp->next;
        }
    }
}

void archer_vs_mob(s_defenders *game)
{
    sfIntRect hitbox_archer = {0};
    sfIntRect hitbox_mob = {0};

    check_archer_vs_mob(game, &game->play.wave->monster, hitbox_archer,
    hitbox_mob);
}
