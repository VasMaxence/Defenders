/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** magic.h
*/

#ifndef _H_TOWER_
#define _H_TOWER_

#include "defense.h"

typedef struct t_tower {
    s_sprite draw;
    s_sprite animated;
    sfIntRect hit_animate;
    sfIntRect hit_tower;
    sfClock *clock;
    int shoot_bool;
    int damage;
    int range;
    int attack_speed;
}s_tower;

#endif
