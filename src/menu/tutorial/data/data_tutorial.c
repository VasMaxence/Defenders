/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** data_tutorial.c
*/

#include "my_defenders.h"

void set_pos_2(s_defenders *game, sfVector2u size_img, sfVector2u size_window)
{
    game->tuto.draw[8].pos.x = (size_window.x / 2) -
    ((size_img.x + 150) * game->data.scale_img.x);
    game->tuto.draw[8].pos.y = (100 * game->data.scale_img.y);
    game->tuto.draw[9].pos.x = (size_window.x / 2) +
    ((150) * game->data.scale_img.x);
    game->tuto.draw[9].pos.y = (100 * game->data.scale_img.y);
    for (int i = 10; i < 14; i++) {
        game->tuto.draw[i].pos.x = game->tuto.draw[i - 2].pos.x;
        game->tuto.draw[i].pos.y = game->tuto.draw[i - 2].pos.y
        + (200 * game->data.scale_img.y) + size_img.y;
    }
    for (int i = 14; i < 20; i++)
        game->tuto.draw[i].pos = game->tuto.draw[i - 6].pos;
    for (int i = 0; i < 20; i++)
        sfSprite_setPosition(game->tuto.draw[i].sprite, game->tuto.draw[i].pos);
}

void set_pos_tuto(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img =
    get_size_img(game->tuto.draw[4].texture, game->data.scale_img);

    for (int i = 0; i < 4; i++) {
        game->tuto.draw[i].pos.x = 0;
        game->tuto.draw[i].pos.y = 0;
    }
    game->tuto.draw[4].pos.x = 0;
    game->tuto.draw[4].pos.y = (size_window.y / 2) - (size_img.y / 2);
    game->tuto.draw[5].pos.x = (size_window.x) - (50 * game->data.scale_img.x);
    game->tuto.draw[5].pos.y = (size_window.y / 2) - (size_img.y / 2);
    size_img = get_size_img(game->tuto.draw[6].texture, game->data.scale_img);
    game->tuto.draw[6].pos.y = 0;
    game->tuto.draw[6].pos.x = size_window.x - size_img.x;
    size_img = get_size_img(game->tuto.draw[7].texture, game->data.scale_img);
    game->tuto.draw[7].pos.y = (150 * game->data.scale_img.y);
    game->tuto.draw[7].pos.x = (size_window.x / 2) - (size_img.x / 2);
    size_img = get_size_img(game->tuto.draw[8].texture, game->data.scale_img);
    set_pos_2(game, size_img, size_window);
}

void set_sound_tuto(s_defenders *game)
{
    game->tuto.music = malloc(sizeof(sfMusic *) * 3);
    game->tuto.music[0] =
    sfMusic_createFromFile("ressources/music/tuto_archer.ogg");
    game->tuto.music[1] =
    sfMusic_createFromFile("ressources/music/tuto_tower.ogg");
    game->tuto.music[2] =
    sfMusic_createFromFile("ressources/music/tuto_evol.ogg");
    for (int i = 0; i < 3; i++)
        sfMusic_setVolume(game->tuto.music[i], game->data.volume_effect);
}

void set_data_tutorial(s_defenders *game)
{
    FILE *fp = fopen("config/tutorial/img.fpc", "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 22; i++) {
        getline(&line, &len, fp);
        line[my_strlen(line) - 1] = '\0';
        game->tuto.draw[i].sprite = sfSprite_create();
        game->tuto.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->tuto.draw[i].sprite,
        game->tuto.draw[i].texture, sfTrue);
        sfSprite_setScale(game->tuto.draw[i].sprite, game->data.scale_img);
    }
    free(line);
    fclose(fp);
    set_pos_tuto(game);
}
