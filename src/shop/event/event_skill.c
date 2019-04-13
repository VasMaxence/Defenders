/*
** EPITECH PROJECT, 2019
** graph
** File description:
** event_skill.c
*/

#include "my_defenders.h"

void write_skill_point(s_defenders *game, char *path)
{
    int fd = open(path, O_TRUNC | O_WRONLY);
    char *str = my_nb_to_str(game->data.skill);

    write(fd, str, my_strlen(str));
    close (fd);
    free(str);
}

void write_fill_skill(s_defenders *game, char *path)
{
    int fd = open(path, O_TRUNC);
    int i = -1;
    char *str = NULL;

    close(fd);
    fd = open(path, O_APPEND | O_WRONLY);
    for (int i = 0; i < 24; i++) {
        str = my_nb_to_str_set(game->shop.stats.level[i]);
        write(fd, str, my_strlen(str));
    }
    close(fd);
}

void up_skill(s_defenders *game, int i)
{
    if (i == 2) {
        game->shop.bool_shop = 0;
        return;
    }
    i -= 12;
    if (i < 0)
        return;
    i /= 2;
    if (game->data.skill) {
        if (game->shop.stats.level[i] == 3)
            return;
        game->shop.stats.level[i]++;
        game->data.skill--;
        sfText_setString(game->shop.text[i].text,
        my_nb_to_str(game->shop.stats.level[i]));
        sfText_setString(game->shop.text[24].text,
        my_nb_to_str(game->data.skill));
        write_skill_point(game, "config/nb_skill.fpc");
        write_fill_skill(game, "config/skill.fpc");
    }
}

void event_up_skill(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0, 0, 0, 0};

    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 2; i < 60; i += 2) {
            hitbox = set_rect_from_sprite(game->shop.draw[i],
            game->data.scale_img);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y) == sfTrue) {
                up_skill(game, i);
            }
        }
    }
}
