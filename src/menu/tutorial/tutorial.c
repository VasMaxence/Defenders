/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** tutorial.c
*/

#include "my_defenders.h"

void destroy_tutorial(s_defenders *game)
{
    for (int i = 0; i < 22; i++) {
        sfSprite_destroy(game->tuto.draw[i].sprite);
        sfTexture_destroy(game->tuto.draw[i].texture);
    }
    for (int i = 0; i < 3; i++)
        sfMusic_destroy(game->tuto.music[i]);
    free(game->tuto.music);
    free(game->tuto.draw);
    free(game->tuto.text);
}

void draw_tuto(s_defenders *game)
{
    if (game->tuto.page == 1) {
        sfRenderWindow_drawSprite(game->window,
        game->tuto.draw[0].sprite, NULL);
        for (int i = 8; i < 14; i++)
            sfRenderWindow_drawSprite(game->window,
            game->tuto.draw[i].sprite, NULL);
    } else if (game->tuto.page == 2) {
        sfRenderWindow_drawSprite(game->window,
        game->tuto.draw[1].sprite, NULL);
        for (int i = 14; i < 20; i++)
            sfRenderWindow_drawSprite(game->window,
            game->tuto.draw[i].sprite, NULL);
    } else if (game->tuto.page == 3) {
        sfRenderWindow_drawSprite(game->window,
        game->tuto.draw[3].sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->tuto.draw[7].sprite, NULL);
    }
}

void event_tuto(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox =
    set_rect_from_sprite(game->tuto.draw[4], game->data.scale_img);

    if (event->type == sfEvtMouseButtonPressed) {
        if (sfIntRect_contains(&hitbox, event->mouseButton.x,
        event->mouseButton.y) == sfTrue)
            page_down(game);
        hitbox = set_rect_from_sprite(game->tuto.draw[5], game->data.scale_img);
        if (sfIntRect_contains(&hitbox, event->mouseButton.x,
        event->mouseButton.y) == sfTrue)
            page_up(game);
        hitbox = set_rect_from_sprite(game->tuto.draw[6], game->data.scale_img);
        if (sfIntRect_contains(&hitbox, event->mouseButton.x,
        event->mouseButton.y) == sfTrue)
            game->tuto.bool = 0;
    }
}

void play_tutorial(s_defenders *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window) && game->tuto.bool) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_tuto(game);
        for (int i = 4; i < 7; i++)
            sfRenderWindow_drawSprite(game->window,
            game->tuto.draw[i].sprite, NULL);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event.type == sfEvtKeyPressed
            && event.key.code == sfKeyEscape)
                game->tuto.bool = 0;
            event_tuto(game, &event);
        }
    }
    destroy_tutorial(game);
}

void launch_tutorial(s_defenders *game)
{
    game->tuto.draw = malloc(sizeof(s_sprite) * 22);
    game->tuto.text = malloc(sizeof(s_text) * 19);
    set_data_tutorial(game);
    set_sound_tuto(game);
    game->tuto.bool = 1;
    game->tuto.page = 1;
    play_tutorial(game);
}
