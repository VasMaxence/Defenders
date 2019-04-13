/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/game/pause/ptr_button_pause.h
*/

#ifndef _PTR_BUTTON_PAUSE_
#define _PTR_BUTTON_PAUSE_

#include "../../../include/my_defenders.h"

typedef struct ptr_button_pause {
    int arg;
    void (*ptr)(s_defenders *, sfEvent *);
}ptr_button_pause;

ptr_button_pause PTR_BUTTON_PAUSE[] = {
    {1, &return_menu_from_pause},
    {2, &resume_game},
    {3, &close_window},
    {0, NULL}
};

#endif /*_PTR_BUTTON_PAUSE_*/
