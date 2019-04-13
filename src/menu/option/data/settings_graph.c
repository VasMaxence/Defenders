/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/data/data_pos_settings.c
*/

#include "my_defenders.h"

void set_pos_graph_settings(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_bg =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);
    sfVector2u size_img =
    get_size_img(game->settings.draw[18].texture, game->data.scale_img);

    game->settings.draw[18].pos.x = game->settings.draw[2].pos.x
    + ((size_bg.x / 2) - (size_img.x / 2));
    game->settings.draw[18].pos.y = game->settings.draw[7].pos.y;
    game->settings.draw[19].pos.x = game->settings.draw[18].pos.x
    - (25 * game->data.scale_img.x);
    game->settings.draw[19].pos.y = game->settings.draw[18].pos.y;
    game->settings.draw[20].pos.x = game->settings.draw[18].pos.x
    - (25 * game->data.scale_img.x) + size_img.x;
    game->settings.draw[20].pos.y = game->settings.draw[18].pos.y;
    for (int i = 21; i < 24; i++) {
        game->settings.draw[i].pos.x = game->settings.draw[i - 3].pos.x;
        game->settings.draw[i].pos.y = game->settings.draw[i - 3].pos.y
        + (200 * game->data.scale_img.y);
    }
}

char *set_text_size(s_defenders *game)
{
    char *width = my_nb_to_str((int)game->mode.width);
    char *height = my_nb_to_str((int)game->mode.height);
    char *ret = malloc(sizeof(char)
    * (my_strlen(height) + my_strlen(width) + 2));

    ret = my_strcat(width, "*");
    ret = my_strcat(ret, height);
    return (ret);
}

void set_pos_size_settings(s_defenders *game, sfVector2u size_window,
sfVector2u size_img)
{
    char *str = set_text_size(game);

    sfText_setString(game->settings.text[3].text, str);
    free(str);
    game->settings.text[3].pos.x = game->settings.draw[18].pos.x
    + ((size_img.x / 2) - (10 * 8 * game->data.scale_img.x));
    game->settings.text[3].pos.y = game->settings.text[2].pos.y
    + (90 * game->data.scale_img.y);
}

void set_pos_fps_settings(s_defenders *game, sfVector2u size_window,
sfVector2u size_img)
{
    sfText_setString(game->settings.text[5].text,
    my_nb_to_str(game->data.framerate));
    game->settings.text[5].pos.x = game->settings.draw[21].pos.x
    + ((size_img.x / 2) - (10 * 8 * game->data.scale_img.x));
    game->settings.text[5].pos.y = game->settings.text[4].pos.y
    + (60 * game->data.scale_img.y);
}

void set_pos_text_graph(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->settings.draw[1].texture, game->data.scale_img);

    game->settings.text[2].pos.x = game->settings.draw[2].pos.x
    + (size_img.x / 2) - (18 * 8 * game->data.scale_img.y);
    game->settings.text[2].pos.y = (game->settings.draw[18].pos.y)
    - (100 * game->data.scale_img.y);
    game->settings.text[4].pos.x = game->settings.draw[2].pos.x
    + (size_img.x / 2) - (14 * 8 * game->data.scale_img.y);
    game->settings.text[4].pos.y = game->settings.text[2].pos.y
    + (230 * game->data.scale_img.y);
    set_pos_size_settings(game, size_window, size_img);
    set_pos_fps_settings(game, size_window, size_img);
}
