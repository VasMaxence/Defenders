/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/options.c
*/

#include "my_defenders.h"

void launch_settings(s_defenders *game, sfEvent *event)
{
    game->settings.draw = malloc(sizeof(struct t_sprite) * 25);
    game->settings.text = malloc(sizeof(struct t_text) * 6);
    game->settings.bool_set = 1;
    set_settings(game);
    sfSprite_setScale(game->settings.draw[7].sprite,
    game->data.scale_bar_music);
    sfSprite_setScale(game->settings.draw[13].sprite,
    game->data.scale_bar_effect);
    play_settings(game, event);
}

void print_button_true_false(s_defenders *game)
{
    if (game->data.boolean.value_music)
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[11].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[10].sprite, NULL);
    if (game->data.boolean.value_effect)
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[17].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[16].sprite, NULL);
}

void draw_music_settings(s_defenders *game)
{
    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[i].sprite, NULL);
    for (int i = 12; i < 16; i++)
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[i].sprite, NULL);
    for (int i = 18; i < 25; i++)
        sfRenderWindow_drawSprite(game->window,
        game->settings.draw[i].sprite, NULL);
    print_button_true_false(game);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(game->window,
        game->settings.text[i].text, NULL);
}

void play_settings(s_defenders *game, sfEvent *event)
{
    while (sfRenderWindow_isOpen(game->window) && game->settings.bool_set) {
        sfRenderWindow_clear(game->window, sfBlack);
        parralax_menu(game);
        draw_music_settings(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event->type == sfEvtKeyPressed
            && event->key.code == sfKeyEscape)
                game->settings.bool_set = 0;
            event_settings_check(game, event);
        }
    }
    destroy_settings(game);
}

void destroy_settings(s_defenders *game)
{
    for (int i = 0; i < 25; i++) {
        sfSprite_destroy(game->settings.draw[i].sprite);
        sfTexture_destroy(game->settings.draw[i].texture);
    }
    for (int i = 0; i < 6; i++)
        sfText_destroy(game->settings.text[i].text);
    sfSprite_destroy(game->settings.alert.sprite);
    sfTexture_destroy(game->settings.alert.texture);
    free(game->settings.draw);
    free(game->settings.text);
}
