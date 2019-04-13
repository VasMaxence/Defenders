/*
** EPITECH PROJECT, 2018
** my_defenders
** File description:
** monster.h
*/

#ifndef MONSTERS_H_
#define MONSTERS_H_

#include "../../../include/my_defenders.h"

typedef struct t_monster{
    int type;
    int life;
    int damage;
    int speed;
    int alive;
    s_sprite draw;
    sfIntRect rect;
    sfClock *clock;
    sfClock *anim;
    double avancement;
    struct t_monster *next;
    struct t_monster *prev;
}s_monster;

typedef struct t_data_monster {
    struct t_monster *monster;
    int nb_monster;
    int basic_m;
    int speed_m;
    int big_m;
}s_data_monster;

#endif
