/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** new_wave.c
*/

#include "my_defenders.h"

void check_new_wave(s_defenders *game, s_monster **wave)
{
    if (*wave == NULL) {
        game->data.wave++;
        if (!(game->data.wave % 3))
            game->data.nb_big++;
        else {
            game->data.nb_basic += 3;
            game->data.nb_speed++;
        }
        game->play.wave->big_m = game->data.nb_big;
        game->play.wave->speed_m = game->data.nb_speed;
        game->play.wave->basic_m = game->data.nb_basic;
        add_new_wave(wave, game);
    }
}
