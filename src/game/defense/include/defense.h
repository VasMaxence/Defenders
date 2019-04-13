/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** defense.h
*/

#ifndef _H_DEFENSE_
#define _H_DEFENSE_

#include "../../../include/my_defenders.h"

#include "archer.h"
#include "tower.h"
#include "spell.h"
#include "magic.h"

typedef struct t_defense {
    s_archer *archer;
    s_magic *magic;
    s_spell *spell;
    s_tower *tower;
}s_defense;

#endif /*_H_DEFENSE_*/
