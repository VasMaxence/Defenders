/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** event_defense.c
*/

#include "my_defenders.h"

sfIntRect set_hitbox_from_rect(s_defenders *game, int i)
{
    sfIntRect ret = {0, 0, 0, 0};

    ret.width = sfTexture_getSize(game->defense.tower[i].draw.texture).x
    * (game->data.scale_img.x) / 3;
    ret.height = sfTexture_getSize(game->defense.tower[i].draw.texture).y
    * (game->data.scale_img.y);
    ret.left = game->defense.tower[i].draw.pos.x;
    ret.top = game->defense.tower[i].draw.pos.y;
    return (ret);
}

void up_tower(s_defenders *game, int i)
{
    sfVector2u size_img =
    sfTexture_getSize(game->defense.tower[i].draw.texture);

    if (game->defense.tower[i].hit_tower.left >= (size_img.x / 3) * 2
    || game->data.gold < 200) {
        return;
    } else {
        game->data.gold -= 200;
        game->defense.tower[i].hit_tower.left += (size_img.x / 3);
        game->defense.tower[i].damage += 10;
        game->defense.tower[i].range += 20;
        game->defense.tower[i].attack_speed -= 45;
        sfSprite_setTextureRect(game->defense.tower[i].draw.sprite,
        game->defense.tower[i].hit_tower);
    }
}

void set_text_gold(s_defenders *game)
{
    game->data.text_gold = sfText_create();
    sfText_setFont(game->data.text_gold, game->data.font);
    sfText_setString(game->data.text_gold,
    my_strcat("GOLD: ", my_nb_to_str(game->data.gold)));
    sfText_setColor(game->data.text_gold, sfBlack);
    sfText_setCharacterSize(game->data.text_gold, 80);
    sfText_setScale(game->data.text_gold, game->data.scale_img);
}

void chekc_clock_gold(s_defenders *game)
{
    sfTime timer = sfClock_getElapsedTime(game->data.clock_gold);

    if (timer.microseconds / 1000 > 500) {
        game->data.gold += 3;
        sfText_setString(game->data.text_gold,
        my_strcat("GOLD: ", my_nb_to_str(game->data.gold)));
        sfClock_restart(game->data.clock_gold);
    }
}

void check_event_tower(s_defenders *game, sfEvent *event)
{
    sfIntRect hitbox = {0, 0, 0, 0};

    if (event->type == sfEvtMouseButtonPressed)
        for (int i = 0; i < 4; i++) {
            hitbox = set_hitbox_from_rect(game, i);
            if (sfIntRect_contains(&hitbox, event->mouseButton.x,
            event->mouseButton.y) == sfTrue) {
                up_tower(game, i);
                return;
            }
        }
        event_archer(game, event, hitbox);
}
