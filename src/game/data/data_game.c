/*
** EPITECH PROJECT, 2019
** graph
** File description:
** data_game.c
*/

#include "my_defenders.h"

void print_wave(s_defenders *game)
{
    sfText_setString(game->play.text, my_nb_to_str(game->data.wave));
    sfText_setPosition(game->play.text, game->play.pos_txt);
    sfRenderWindow_drawText(game->window, game->play.text, NULL);
    sfText_setString(game->play.text2, my_nb_to_str(game->play.life));
    sfText_setPosition(game->play.text2, game->play.pos_txt2);
    sfRenderWindow_drawText(game->window, game->play.text2, NULL);
}

void set_text_wave(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);

    game->play.text = sfText_create();
    sfText_setString(game->play.text, my_nb_to_str(game->data.wave));
    sfText_setColor(game->play.text, sfBlack);
    sfText_setCharacterSize(game->play.text, 80);
    sfText_setFont(game->play.text, game->data.font);
    sfText_setScale(game->play.text, game->data.scale_img);
    game->play.pos_txt.x = size_window.x - (300 * game->data.scale_img.x);
    game->play.pos_txt.y = 0;
    game->play.text2 = sfText_create();
    sfText_setString(game->play.text2, my_nb_to_str(game->play.life));
    sfText_setColor(game->play.text2, sfBlack);
    sfText_setCharacterSize(game->play.text2, 80);
    sfText_setFont(game->play.text2, game->data.font);
    sfText_setScale(game->play.text2, game->data.scale_img);
    game->play.pos_txt2.x = size_window.x - (100 * game->data.scale_img.x);
    game->play.pos_txt2.y = 0;
}

void set_data_play(s_defenders *game)
{
    set_data_overlay(game);
    set_text_wave(game);
}
