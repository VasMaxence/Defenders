/*
** EPITECH PROJECT, 2018
** my_defenders
** File description:
** liste mob
*/

#include "my_defenders.h"

void set_newt_data_mob(s_monster **wave, s_defenders *game)
{
    s_monster *tmp = *wave;

    while (tmp) {
        if (tmp->type == 3)
            tmp->life += 35 * game->data.wave;
        else {
            tmp->life += (12 + (5 * game->data.wave));
            tmp->damage += 3 * game->data.wave;
        }
        tmp = tmp->next;
    }
}

void add_new_wave(s_monster **tmp, s_defenders *game)
{
    while (game->play.wave->basic_m-- > 0)
        add_end(tmp, "config/monster/basic.fpc");
    while (game->play.wave->speed_m-- > 0)
        add_end(tmp, "config/monster/speed.fpc");
    while (game->play.wave->big_m > 0) {
        add_end(tmp, "config/monster/big.fpc");
        game->play.wave->big_m--;
    }
    set_newt_data_mob(&game->play.wave->monster, game);
    set_rect_mob(&game->play.wave->monster, game);
}

s_data_monster *add_monster(char *path_data, s_defenders *game)
{
    s_data_monster *data;
    int i = 0;

    data = malloc(sizeof(s_data_monster));
    data->monster = NULL;
    open_wave(data, path_data);
    game->data.wave = 1;
    game->data.nb_basic = data->basic_m;
    game->data.nb_speed = data->speed_m;
    game->data.nb_big = data->big_m;
    while (data->basic_m-- > 0)
        add_end(&data->monster, "config/monster/basic.fpc");
    while (data->speed_m-- > 0)
        add_end(&data->monster, "config/monster/speed.fpc");
    while (data->big_m > 0) {
        add_end(&data->monster, "config/monster/big.fpc");
        data->big_m--;
    }
    return (data);
}
