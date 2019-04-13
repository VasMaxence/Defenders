/*
** EPITECH PROJECT, 2019
** graph
** File description:
** set_data_pause2.c
*/

#include "my_defenders.h"

void set_text_pause_pos(s_defenders *game)
{
    for (int i = 0; i < 3; i++) {
        game->pause.text[i].pos.x = game->pause.draw[i + 1].pos.x + 20;
        game->pause.text[i].pos.y = game->pause.draw[i + 1].pos.y + 20;
        sfText_setPosition(game->pause.text[i].text, game->pause.text[i].pos);
    }
}
