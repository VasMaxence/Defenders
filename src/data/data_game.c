/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/data/data_game.c
*/

#include "../include/my_defenders.h"

void set_volume_audio(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    game->data.volume_music = 0;
    game->data.volume_effect = 0;
    while (getline(&line, &len, fp) != -1) {
        if (my_strcmp(line, "  music:") == 8) {
            getline(&line, &len, fp);
            game->data.volume_music = my_getnbr(line);
        } else if (my_strcmp(line, "  effect:") == 9) {
            getline(&line, &len, fp);
            game->data.volume_effect = my_getnbr(line);
        }
    }
    fclose(fp);
    free(line);
}

int set_font(s_defenders *game)
{
    game->data.font = sfFont_createFromFile("ressources/font/main_font.otf");
    game->play.bool_menu = 0;
    set_volume_audio(game, "config/music.fpc");
    return (0);
}

int set_value_from_file(char *str, int *val)
{
    FILE *fp = fopen("config/window.fpc", "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return (0);
    while (getline(&line, &len, fp) != -1) {
        if (my_strcmp(line, str) == my_strlen(str)) {
            getline(&line, &len, fp);
            *val = my_getnbr(line);
        }
    }
    free(line);
    fclose(fp);
    return (1);
}

int verif_data_window(s_defenders *game)
{
    if (game->mode.width <= 0)
        return (84);
    else if (game->mode.height <= 0)
        return (84);
    else if (game->data.framerate <= 0)
        return (84);
    return (0);
}

int set_data_game(s_defenders *game)
{
    game->mode.width = 0;
    game->mode.height = 0;
    game->mode.bitsPerPixel = 32;
    game->data.framerate = 0;
    game->data.vsync = 0;
    set_value_from_file("  width:", &game->mode.width);
    set_value_from_file("  height:", &game->mode.height);
    set_value_from_file("  FPS:", &game->data.framerate);
    set_value_from_file("  vsync:", &game->data.vsync);
    game->data.scale_img.x = (float)game->mode.width / 1920;
    game->data.scale_img.y = (float)game->mode.height / 1080;
    if (verif_data_window(game))
        return (1);
    game->window = sfRenderWindow_create(game->mode, "MY_DEFENDERS",
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(game->window, game->data.framerate);
    if (game->data.vsync)
        sfRenderWindow_setVerticalSyncEnabled(game->window, sfTrue);
    return (0);
}
