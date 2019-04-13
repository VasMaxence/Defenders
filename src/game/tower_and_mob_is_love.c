/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** tower_and_mob_is_love.c
*/

#include "my_defenders.h"

sfIntRect set_range_tower(s_defenders *game, int i)
{
    sfIntRect ret = set_rect_from_sprite(game->defense.tower[i].draw,
    game->data.scale_img);

    ret.left -= game->defense.tower[i].range / 4;
    ret.width += (game->defense.tower[i].range) / 2;
    ret.top -= game->defense.tower[i].range / 4;
    ret.height += (game->defense.tower[i].range) / 2;
    return (ret);
}

void play_animation_tower_on_mob(s_defenders *game, s_monster *tmp, int i)
{
    game->defense.tower[i].shoot_bool = 1;
    sfClock_restart(game->defense.tower[i].clock);
    game->defense.tower[i].hit_animate.left = 0;
    game->defense.tower[i].animated.pos.x = tmp->draw.pos.x;
    game->defense.tower[i].animated.pos.y = tmp->draw.pos.y;
    sfSprite_setTextureRect(game->defense.tower[i].animated.sprite,
    game->defense.tower[i].hit_animate);
    sfSprite_setPosition(game->defense.tower[i].animated.sprite,
    game->defense.tower[i].animated.pos);
}

void tower_attack(s_monster *tmp, int i, s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->defense.tower[i].clock);

    if (timer.microseconds / 1000 > game->defense.tower[i].attack_speed * 3) {
        sfMusic_play(game->play.music[1]);
        play_animation_tower_on_mob(game, tmp, i);
        tmp->life -= game->defense.tower[i].damage;
        sfClock_restart(game->defense.tower[i].clock);
    }
}

void check_tower_vs_mob(s_defenders *game, s_monster **wave,
sfIntRect hitbox_tower, sfIntRect hitbox_mob)
{
    s_monster *tmp;

    for (int i = 0; i < 4; i++) {
        tmp = *wave;
        hitbox_tower = set_range_tower(game, i);
        while (tmp) {
            hitbox_mob = set_rect_from_sprite(tmp->draw, game->data.scale_img);
            if (sfIntRect_intersects(&hitbox_tower, &hitbox_mob, NULL)
            == sfTrue)
                tower_attack(tmp, i, game);
            tmp = tmp->next;
        }
    }
}

void tower_vs_mob(s_defenders *game)
{
    sfIntRect hitbox_tower = {0};
    sfIntRect hitbox_mob = {0};

    check_tower_vs_mob(game, &game->play.wave->monster, hitbox_tower,
    hitbox_mob);
}
