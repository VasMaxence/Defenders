/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** event_end.c
*/

#include "my_defenders.h"

void event_button_end(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox1 = set_rect_from_sprite(game->play.end.draw[2],
    game->data.scale_img);
    sfIntRect hitbox2 = set_rect_from_sprite(game->play.end.draw[3],
    game->data.scale_img);

    if (event->type == sfEvtMouseButtonPressed)
        if (sfIntRect_contains(&hitbox1, event->mouseButton.x,
        event->mouseButton.y) == sfTrue) {
            game->play.bool_menu = 1;
            game->play.end.bool = 0;
            game->play.bool = 0;
        } else if (sfIntRect_contains(&hitbox2, event->mouseButton.x,
        event->mouseButton.y) == sfTrue) {
            sfRenderWindow_close(game->window);
        }
}

void set_text_end(s_defenders *game, int i)
{
    game->play.end.text.text = sfText_create();
    if (i)
        sfText_setString(game->play.end.text.text, "YOU WIN");
    else
        sfText_setString(game->play.end.text.text, "YOU LOOSE");
    sfText_setColor(game->play.end.text.text, sfBlack);
    sfText_setFont(game->play.end.text.text, game->data.font);
    sfText_setCharacterSize(game->play.end.text.text, 80);
    sfText_setScale(game->play.end.text.text, game->data.scale_img);
    game->play.end.text.pos.x = (920 * game->data.scale_img.x);
    game->play.end.text.pos.y = (200 * game->data.scale_img.y);
    sfText_setPosition(game->play.end.text.text,
    game->play.end.text.pos);
}
