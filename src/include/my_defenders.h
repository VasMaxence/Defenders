/*
** EPITECH PROJECT, 2019
** graph
** File description:
** my/my_defenders.h
*/

#ifndef _H_MY_DEFENDERS_
#define _H_MY_DEFENDERS_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Config.h>
#include "../../lib/my/my.h"

typedef struct t_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
}s_sprite;

typedef struct t_text {
    sfText *text;
    sfVector2f pos;
}s_text;

typedef struct t_tmapping {
    char **map;
    int **map_sp;
}s_tmapping;

typedef int bool;
#define true 1
#define false 0

#include "../game/monsters/include/monster.h"
#include "../menu/include/menu.h"
#include "../game/include/play.h"
#include "../menu/option/include/option.h"
#include "../shop/include/shop.h"
#include "../game/defense/include/defense.h"
#include "../menu/tutorial/include/tutorial.h"

typedef struct boolean {
    bool value_music;
    bool value_effect;
}boolean;

typedef struct t_intro {
    s_sprite draw;
    sfColor color;
    sfClock *clock;
    int bool;
    int bool_c;
}s_intro;

typedef struct t_data {
    sfVector2f scale_img;
    sfVector2f scale_bar_music;
    sfVector2f scale_bar_effect;
    sfFont *font;
    sfText *text_gold;
    sfClock *clock_gold;
    int framerate;
    int vsync;
    int volume_music;
    int volume_effect;
    int skill;
    boolean boolean;
    int gold;
    int wave;
    int nb_monster;
    int nb_basic;
    int nb_speed;
    int nb_big;
}s_data;

typedef struct t_defenders {
    s_data data;
    s_menu menu;
    s_pause pause;
    s_play play;
    s_settings settings;
    s_shop shop;
    s_intro intro;
    s_sprite *tileset;
    s_defense defense;
    s_tutorial tuto;
    sfVideoMode mode;
    sfRenderWindow *window;
}s_defenders;

#include "prototype.h"

#endif /*_H_MY_DEFENDERS_*/
