/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** magic.h
*/

#ifndef _H_SPELL_
#define _H_SPELL_

#include "defense.h"

typedef struct t_spell {
    s_sprite draw;
    sfIntRect rect;
    sfClock *reload_clock;
    sfClock *anim_clock;
    sfText *reload;
    int using;
    int damage;
    int time_reload;
    int waiting;
}s_spell;

#endif
