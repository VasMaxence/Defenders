/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** data_sound.c
*/

#include "my_defenders.h"

void set_sound_play(s_defenders *game)
{
    game->play.music = malloc(sizeof(sfMusic *) * 3);
    game->play.music[0] =
    sfMusic_createFromFile("ressources/music/music_battle_epic.ogg");
    game->play.music[1] =
    sfMusic_createFromFile("ressources/music/tower_sound.ogg");
    game->play.music[2] =
    sfMusic_createFromFile("ressources/music/death_mob.ogg");
    sfMusic_setLoop(game->play.music[0], sfTrue);
    sfMusic_setVolume(game->play.music[0], game->data.volume_music);
    sfMusic_setVolume(game->play.music[1], game->data.volume_effect);
    sfMusic_setVolume(game->play.music[2], game->data.volume_effect);
}
