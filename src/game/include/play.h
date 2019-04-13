/*
** EPITECH PROJECT, 2019
** graph
** File description:
** play.h
*/

#ifndef _H_PLAY_
#define _H_PLAY_

#include "../../include/my_defenders.h"

typedef struct t_overlay {
    s_sprite *draw;
}s_overlay;

typedef struct t_pause {
    s_sprite *draw;
    s_text *text;
    int bool;
}s_pause;

typedef struct t_end {
    s_sprite *draw;
    s_text text;
    int bool;
}s_end;

typedef struct t_play {
    s_sprite *draw;
    sfClock **clock;
    s_overlay overlay;
    s_tmapping tilemapping;
    sfMusic **music;
    sfText *text;
    sfVector2f pos_txt;
    sfText *text2;
    sfVector2f pos_txt2;
    int life;
    int bool;
    int bool_menu;
    s_data_monster *wave;
    s_end end;
}s_play;

#endif /*_H_PLAY_*/
