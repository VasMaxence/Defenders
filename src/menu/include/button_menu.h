/*
** EPITECH PROJECT, 2019
** graph
** File description:
** button_menu.h
*/

#ifndef _PTR_MENU_
#define _PTR_MENU_

#include "../../include/my_defenders.h"

void close_window(s_defenders *, sfEvent *);
void launch_play(s_defenders *, sfEvent *);
void launch_settings(s_defenders *, sfEvent *);
void launch_shop(s_defenders *, sfEvent *);

typedef struct button_menu {
    int arg;
    void (*ptr)(s_defenders *, sfEvent *);
}button_menu;

button_menu PTR_BUTTON[] = {
    {1, &launch_play},
    {2, &launch_shop},
    {3, &launch_settings},
    {4, &close_window},
    {0, NULL}
};

#endif /*_PTR_MENU_*/
