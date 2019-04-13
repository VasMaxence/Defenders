/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/menu.c
*/

#include "../include/my_defenders.h"

void launch_menu(s_defenders *game)
{
    game->menu.draw = malloc(sizeof(struct t_sprite) * 22);
    game->menu.clock = malloc(sizeof(sfClock *) * 7);
    game->shop.stats.level = malloc(sizeof(int) * 24);
    for (int i = 0; i < 7; i++)
        game->menu.clock[i] = sfClock_create();
    set_data_menu(game);
    set_skill_level(game, "config/skill.fpc");
    set_nb_skill(game, "config/nb_skill.fpc");
    play_menu(game);
}

void check_event_menu(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = set_rect_from_sprite(game->menu.tuto,
    game->data.scale_img);

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event->type == sfEvtMouseButtonPressed) {
        if (sfIntRect_contains(&hitbox, event->mouseButton.x,
        event->mouseButton.y) == sfTrue)
            launch_tutorial(game);
    }
    mouse_pos_on_button(game, event);
    choose_button_with_keypad(game, event);
    event_of_button_menu(game, event);
    event_of_enter_menu(game, event);
}

void play_menu(s_defenders *game)
{
    sfEvent event;

    sfMusic_play(game->menu.music);
    game->play.bool_menu = 1;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        parralax_menu(game);
        for (int i = 14; i < 18; i++)
            sfRenderWindow_drawSprite(game->window,
            game->menu.draw[i].sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->menu.tuto.sprite, NULL);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            check_event_menu(game, &event);
        }
    }
    if (game->play.bool_menu)
        destroy_menu(game);
}

void destroy_menu(s_defenders *game)
{
    for (int i = 0; i < 22; i++)
        sfTexture_destroy(game->menu.draw[i].texture);
    for (int i = 0; i < 22; i++)
        sfSprite_destroy(game->menu.draw[i].sprite);
    for (int i = 0; i < 7; i++)
        sfClock_destroy(game->menu.clock[i]);
    sfTexture_destroy(game->menu.tuto.texture);
    sfSprite_destroy(game->menu.tuto.sprite);
    sfMusic_destroy(game->menu.music);
    free(game->menu.draw);
    free(game->menu.clock);
}

void close_window(s_defenders *game, sfEvent *event)
{
    sfRenderWindow_close(game->window);
}
