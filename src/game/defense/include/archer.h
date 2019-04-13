/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** archer.h
*/

#ifndef _H_ARCHER_
#define _H_ARCHER_

#include "defense.h"

typedef struct t_archer {
    s_sprite draw;
    s_sprite animated;
    sfIntRect hit_animate;
    sfIntRect hit_archer;
    sfClock *clock;
    int shoot_bool;
    int damage;
    int range;
    int attack_speed;
}s_archer;

#endif
