/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/shop/shop.c
*/

#include "my_defenders.h"

void launch_shop(s_defenders *game, sfEvent *event)
{
    game->shop.draw = malloc(sizeof(struct t_sprite) * 60);
    game->shop.text = malloc(sizeof(struct t_text) * 25);
    game->shop.bool_shop = 1;
    set_data_shop(game);
    set_text_shop(game);
    play_shop(game, event);
}

void draw_shop(s_defenders *game)
{
    for (int i = 0; i < 60; i++)
        sfRenderWindow_drawSprite(game->window,
        game->shop.draw[i].sprite, NULL);
    for (int i = 0; i < 25; i++)
        sfRenderWindow_drawText(game->window,
        game->shop.text[i].text, NULL);
}

void play_shop(s_defenders *game, sfEvent *event)
{
    while (sfRenderWindow_isOpen(game->window) && game->shop.bool_shop) {
        sfRenderWindow_clear(game->window, sfBlack);
        parralax_menu(game);
        draw_shop(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event->type == sfEvtKeyPressed
            && event->key.code == sfKeyEscape)
                game->shop.bool_shop = 0;
            event_up_skill(game, event);
        }
    }
    destroy_shop(game);
}

void destroy_shop(s_defenders *game)
{
    for (int i = 0; i < 60; i++) {
        sfSprite_destroy(game->shop.draw[i].sprite);
        sfTexture_destroy(game->shop.draw[i].texture);
    }
    for (int i = 0; i < 25; i++)
        sfText_destroy(game->shop.text[i].text);
    free(game->shop.draw);
    free(game->shop.text);
}
