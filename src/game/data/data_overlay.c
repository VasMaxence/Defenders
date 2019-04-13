/*
** EPITECH PROJECT, 2019
** graph
** File description:
** data_overlay.c
*/

#include "my_defenders.h"

void set_img_overlay(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 15; i++) {
        getline(&line, &len, fp);
        line[my_strlen(line) - 1] = '\0';
        game->play.overlay.draw[i].sprite = sfSprite_create();
        game->play.overlay.draw[i].texture =
        sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->play.overlay.draw[i].sprite,
        game->play.overlay.draw[i].texture, sfTrue);
        sfSprite_setScale(game->play.overlay.draw[i].sprite,
        game->data.scale_img);
    }
    free(line);
    fclose(fp);
}

void set_pos_overlay2(s_defenders *game, sfVector2u size_window,
sfVector2u size_img)
{
    for (int i = 3; i < 15; i++) {
        game->play.overlay.draw[i].pos.x = game->play.overlay.draw[i - 2].pos.x
        + size_img.x + (20 * game->data.scale_img.x);
        game->play.overlay.draw[i].pos.y = game->play.overlay.draw[i - 2].pos.y;
    }
}

void set_pos_overlay(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img =
    get_size_img(game->play.overlay.draw[0].texture, game->data.scale_img);

    game->play.overlay.draw[0].pos.x = 0;
    game->play.overlay.draw[0].pos.y = size_window.y - ((size_img.y / 3) * 2);
    game->play.overlay.draw[1].pos.x = game->play.overlay.draw[0].pos.x +
    (40 * game->data.scale_img.x);
    game->play.overlay.draw[1].pos.y = game->play.overlay.draw[0].pos.y +
    (20 * game->data.scale_img.y);
    size_img =
    get_size_img(game->play.overlay.draw[1].texture, game->data.scale_img);
    game->play.overlay.draw[2].pos.x = game->play.overlay.draw[1].pos.x;
    game->play.overlay.draw[2].pos.y = game->play.overlay.draw[1].pos.y +
    ((20 * game->data.scale_img.y) + (size_img.y));
    set_pos_overlay2(game, size_window, size_img);
    for (int i = 0; i < 15; i++) {
        sfSprite_setPosition(game->play.overlay.draw[i].sprite,
        game->play.overlay.draw[i].pos);
    }
}

void set_data_overlay(s_defenders *game)
{
    game->play.overlay.draw = malloc(sizeof(struct t_sprite) * 15);
    set_img_overlay(game, "config/overlay/img.fpc");
    set_pos_overlay(game);
}
