/*
** EPITECH PROJECT, 2019
** graph
** File description:
** menu.h
*/

#ifndef _H_MENU_
#define _H_MENU_

#include "../../include/my_defenders.h"

typedef struct t_menu {
    s_sprite *draw;
    s_sprite tuto;
    sfClock **clock;
    int button_value;
    sfMusic *music;
}s_menu;

#endif /*_H_MENU_*/
