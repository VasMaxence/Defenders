/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** magic.h
*/

#ifndef _H_MAGIC_
#define _H_MAGIC_

#include "defense.h"

typedef struct t_magic {
    s_sprite draw;
    sfText *reload;
    int damage;
    int range;
    int time_reload;
}s_magic;

#endif
