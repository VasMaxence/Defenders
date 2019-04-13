/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** tutorial.h
*/

#ifndef _H_TUTORIAL_
#define _H_TUTORIAL_

#include "../../../include/my_defenders.h"

typedef struct t_tutorial {
    s_sprite *draw;
    s_text *text;
    sfMusic **music;
    int page;
    int bool;
}s_tutorial;

#endif /*_H_TUTORIAL_*/
