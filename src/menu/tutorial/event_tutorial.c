/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** event_tutorial.c
*/

#include "my_defenders.h"

void page_up(s_defenders *game)
{
    sfMusic_stop(game->tuto.music[game->tuto.page - 1]);
    game->tuto.page++;
    if (game->tuto.page < 1) {
        game->tuto.page = 3;
    } else if (game->tuto.page > 3) {
        game->tuto.page = 1;
    }
    sfMusic_play(game->tuto.music[game->tuto.page - 1]);
}

void page_down(s_defenders *game)
{
    sfMusic_stop(game->tuto.music[game->tuto.page - 1]);
    game->tuto.page--;
    if (game->tuto.page < 1) {
        game->tuto.page = 3;
    } else if (game->tuto.page > 3) {
        game->tuto.page = 1;
    }
    sfMusic_play(game->tuto.music[game->tuto.page - 1]);
}
