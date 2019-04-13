/*
** EPITECH PROJECT, 2019
** graph
** File description:
** intro.c
*/

#include "my_defenders.h"

void set_intro(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);

    game->intro.draw.sprite = sfSprite_create();
    game->intro.draw.texture =
    sfTexture_createFromFile("ressources/intro/troll.png", NULL);
    sfSprite_setTexture(game->intro.draw.sprite, game->intro.draw.texture,
    sfTrue);
    sfSprite_setScale(game->intro.draw.sprite, game->data.scale_img);
    game->intro.clock = sfClock_create();
    sfVector2u size_img =
    get_size_img(game->intro.draw.texture, game->data.scale_img);
    game->intro.draw.pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->intro.draw.pos.y = (size_window.y / 2) - (size_img.y / 2);
    sfSprite_setPosition(game->intro.draw.sprite, game->intro.draw.pos);
    game->intro.color = sfSprite_getColor(game->intro.draw.sprite);
    game->intro.color.a = 11;
    sfSprite_setColor(game->intro.draw.sprite, game->intro.color);
    game->intro.bool = 1;
    game->intro.bool_c = 1;
}

void check_anim_color(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->intro.clock);

    if (timer.microseconds / 1000 > 80) {
        if (game->intro.color.a < 230 && game->intro.bool_c)
            game->intro.color.a += 10;
        else {
            game->intro.bool_c = 0;
            game->intro.color.a -= 10;
        }
        sfSprite_setColor(game->intro.draw.sprite, game->intro.color);
        sfClock_restart(game->intro.clock);
    }
    if (game->intro.color.a <= 10)
        game->intro.bool = 0;
}

void destroy_intro(s_defenders *game)
{
    sfSprite_destroy(game->intro.draw.sprite);
    sfTexture_destroy(game->intro.draw.texture);
    sfClock_destroy(game->intro.clock);
}

void play_intro(s_defenders *game)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window) && game->intro.bool) {
        sfRenderWindow_clear(game->window, sfWhite);
        check_anim_color(game);
        sfRenderWindow_drawSprite(game->window, game->intro.draw.sprite, NULL);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event.type == sfEvtKeyPressed)
                game->intro.bool = 0;
        }
    }
    destroy_intro(game);
}

void launch_intro(s_defenders *game)
{
    set_intro(game);
    play_intro(game);
}
