/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/shop/data/data_shop_pos.c
*/

#include "my_defenders.h"

void pos_shop4(s_defenders *game, sfVector2u size_window, sfVector2u size_bg)
{
    for (int i = 20; i < 60; i++) {
        game->shop.draw[i].pos.x = game->shop.draw[i - 8].pos.x + size_bg.x
        + (25 * game->data.scale_img.x);
        game->shop.draw[i].pos.y = game->shop.draw[i - 8].pos.y;
    }
}

void pos_shop3(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->shop.draw[12].texture, game->data.scale_img);
    sfVector2u size_bg =
    get_size_img(game->shop.draw[6].texture, game->data.scale_img);

    game->shop.draw[12].pos.x = game->shop.draw[6].pos.x + (size_bg.x / 2)
    - (size_img.x / 2);
    game->shop.draw[12].pos.y = game->shop.draw[6].pos.y + (size_bg.y / 2)
    - (15 *game->data.scale_img.y) - (size_img.y * 2);
    game->shop.draw[13].pos.x = game->shop.draw[12].pos.x + size_img.x
    - (75 * game->data.scale_img.x);
    game->shop.draw[13].pos.y = game->shop.draw[12].pos.y + size_img.y
    - (45 * game->data.scale_img.y);
    for (int i = 14; i < 20; i++) {
        game->shop.draw[i].pos.x = game->shop.draw[i - 2].pos.x;
        game->shop.draw[i].pos.y = game->shop.draw[i - 2].pos.y +
        size_img.y + (10 * game->data.scale_img.y);
    }
    pos_shop4(game, size_window, size_bg);
}

void pos_shop2(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->shop.draw[5].texture, game->data.scale_img);
    sfVector2u size_bg =
    get_size_img(game->shop.draw[0].texture, game->data.scale_img);

    game->shop.draw[5].pos.x = game->shop.draw[0].pos.x + size_bg.x
    - size_img.x - 50;
    game->shop.draw[5].pos.y = game->shop.draw[0].pos.y + 30;
    size_img = get_size_img(game->shop.draw[6].texture, game->data.scale_img);
    game->shop.draw[6].pos.x = (size_window.x / 2)
    - (size_img.x * 3) - (67.5 * game->data.scale_img.x);
    game->shop.draw[6].pos.y = (size_window.y / 2) - (size_img.y / 2.5);
    for (int i = 7; i < 12; i++) {
        game->shop.draw[i].pos.x = game->shop.draw[i - 1].pos.x +
        (25 * game->data.scale_img.x) + size_img.x;
        game->shop.draw[i].pos.y = game->shop.draw[i - 1].pos.y;
    }
    pos_shop3(game, size_window);
}

void pos_window_shop(s_defenders *game, sfVector2u size_window)
{
    sfVector2u size_img =
    get_size_img(game->shop.draw[0].texture, game->data.scale_img);

    game->shop.draw[0].pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->shop.draw[0].pos.y = (size_window.y / 2)
    - ((900 * game->data.scale_img.y) / 2);
    size_img = get_size_img(game->shop.draw[1].texture, game->data.scale_img);
    game->shop.draw[1].pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->shop.draw[1].pos.y = game->shop.draw[0].pos.y - 30;
    size_img = get_size_img(game->shop.draw[2].texture, game->data.scale_img);
    game->shop.draw[2].pos.x = game->shop.draw[0].pos.x - (size_img.x / 2);
    game->shop.draw[2].pos.y = game->shop.draw[0].pos.y - (size_img.y / 2);
    size_img = get_size_img(game->shop.draw[3].texture, game->data.scale_img);
    game->shop.draw[3].pos.x = (size_window.x / 4) - (size_img.x / 2);
    game->shop.draw[4].pos.x = ((size_window.x / 4) * 3) - (size_img.x / 2);
    game->shop.draw[3].pos.y = game->shop.draw[0].pos.y + 80 - size_img.y;
    game->shop.draw[4].pos.y = game->shop.draw[0].pos.y + 80 - size_img.y;
    pos_shop2(game, size_window);
}
