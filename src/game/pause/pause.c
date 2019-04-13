/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/game/pause/pause.c
*/

#include "my_defenders.h"

void draw_pause(s_defenders *game)
{
    sfRenderWindow_drawSprite(game->window, game->tileset[0].sprite, NULL);
    print_map(game);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window,
        game->defense.tower[i].draw.sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window,
        game->pause.draw[i].sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(game->window,
        game->pause.text[i].text, NULL);
}

void play_pause(s_defenders *game, sfEvent *event)
{
    game->pause.bool = 1;
    while (sfRenderWindow_isOpen(game->window) && game->pause.bool) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_pause(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event->type == sfEvtKeyPressed &&
            event->key.code == sfKeyEscape)
                game->pause.bool = 0;
            check_event_button_pause(game, event);
        }
    }
}

void destroy_pause(s_defenders *game)
{
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(game->pause.draw[i].sprite);
        sfTexture_destroy(game->pause.draw[i].texture);
        if (i < 3)
            sfText_destroy(game->pause.text[i].text);
    }
    free(game->pause.draw);
    free(game->pause.text);
}
