/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ptr_overlay.h
*/

#ifndef _PTR_OVERLAY_
#define _PTR_OVERLAY_

#include "../../include/my_defenders.h"

void up_tower(s_defenders *, int);
void up_archer(s_defenders *, int);
void use_fireball(s_defenders *, int);

typedef struct evt_overlay {
    int arg;
    void (*ptr)(s_defenders *, int);
}evt_overlay;

evt_overlay PTR_FUNC[] = {
    {1, &up_archer},
    {2, &up_archer},
    {3, &up_archer},
    {7, &up_tower},
    {8, &up_tower},
    {9, &up_tower},
    {10, &up_tower},
    {11, &use_fireball},
    {0, NULL}
};

#endif /*_PTR_OVERLAY_*/
