/*
** EPITECH PROJECT, 2019
** graph
** File description:
** shop.h
*/

#ifndef _H_SHOP_
#define _H_SHOP_

#include "../../include/my_defenders.h"

typedef struct t_stat {
    int nb_point_level;
    int *level;
}s_stat;

typedef struct t_shop {
    s_sprite *draw;
    s_text *text;
    s_stat stats;
    int bool_shop;
}s_shop;

#endif /*_H_SHOP_*/
