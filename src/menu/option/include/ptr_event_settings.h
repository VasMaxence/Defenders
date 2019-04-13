/*
** EPITECH PROJECT, 2019
** graph
** File description:
** ptr_event_settings.h
*/

#ifndef _PTR_SETTINGS_
#define _PTR_SETTINGS_

#include "../../../include/my_defenders.h"

void up_music(s_defenders *, sfEvent *);
void down_music(s_defenders *, sfEvent *);
void play_and_stop_music(s_defenders *, sfEvent *);
void up_effect(s_defenders *, sfEvent *);
void down_effect(s_defenders *, sfEvent *);
void play_and_stop_effect(s_defenders *, sfEvent *);
void down_fps(s_defenders *, sfEvent *);
void up_fps(s_defenders *, sfEvent *);
void up_size(s_defenders *, sfEvent *);
void down_size(s_defenders *, sfEvent *);
void close_settings(s_defenders *, sfEvent *);

typedef struct ptr_seettings {
    int arg;
    void (*ptr)(s_defenders *, sfEvent *);
}ptr_settings;

ptr_settings PTR_BUTTON_SETTINGS[] = {
    {8, &down_music},
    {9, &up_music},
    {10, &play_and_stop_music},
    {11, &play_and_stop_music},
    {14, &down_effect},
    {15, &up_effect},
    {16, &play_and_stop_effect},
    {17, &play_and_stop_effect},
    {19, &down_size},
    {20, &up_size},
    {22, &down_fps},
    {23, &up_fps},
    {24, &close_settings},
    {0, NULL}
};

#endif /*_PTR_SETTINGS_*/
