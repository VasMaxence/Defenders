/*
** EPITECH PROJECT, 2019
** graph
** File description:
** event_graph.c
*/

#include "my_defenders.h"

void down_fps(s_defenders *game, sfEvent *event)
{
    if (game->data.framerate > 20) {
        game->data.framerate -= 5;
        sfText_setString(game->settings.text[5].text,
        my_nb_to_str(game->data.framerate));
        sfRenderWindow_setFramerateLimit(game->window, game->data.framerate);
        resize_all(game);
    }
}

void up_fps(s_defenders *game, sfEvent *event)
{
    if (game->data.framerate < 145) {
        game->data.framerate += 5;
        sfText_setString(game->settings.text[5].text,
        my_nb_to_str(game->data.framerate));
        sfRenderWindow_setFramerateLimit(game->window, game->data.framerate);
        resize_all(game);
    }
}

void resize_all(s_defenders *game)
{
    int fd = open("config/window.fpc", O_TRUNC);
    char *tab[9] = {"  width:\n", "1920\n", "  height:\n", "1080\n", "  FPS:\n"
    , "60\n", "  vsync:\n", "0\n", NULL};
    int i = -1;

    close(fd);
    fd = open("config/window.fpc", O_APPEND | O_WRONLY);
    tab[1] = my_nb_to_str_set((int)game->mode.width);
    tab[3] = my_nb_to_str_set((int)game->mode.height);
    tab[5] = my_nb_to_str_set((int)game->data.framerate);
    while (tab[++i])
        write(fd, tab[i], my_strlen(tab[i]));
    close(fd);
}

void up_size(s_defenders *game, sfEvent *event)
{
    if (game->mode.width < 1920) {
        game->mode.width = 1920;
        game->mode.height = 1080;
        sfText_setString(game->settings.text[3].text, set_text_size(game));
        resize_all(game);
    }
}

void down_size(s_defenders *game, sfEvent *event)
{
    if (game->mode.width > 1280) {
        game->mode.width = 1280;
        game->mode.height = 720;
        sfText_setString(game->settings.text[3].text, set_text_size(game));
        resize_all(game);
    }
}
