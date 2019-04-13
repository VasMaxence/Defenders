/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** mob_alive.c
*/

#include "my_defenders.h"

void delete(s_monster **wave, s_monster *del)
{
    if (*wave == NULL || del == NULL)
        return;
    if (*wave == del)
        *wave = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}

void delete_mob_dead(s_monster **wave, s_defenders *game)
{
    s_monster *tmp = *wave;

    while (tmp) {
        if (!(tmp->alive)) {
            sfSprite_destroy(tmp->draw.sprite);
            sfTexture_destroy(tmp->draw.texture);
            sfClock_destroy(tmp->clock);
            sfClock_destroy(tmp->anim);
            delete(wave, tmp);
        }
        tmp = tmp->next;
    }
}

void check_mob_on_map(s_monster **wave, s_defenders *game)
{
    s_monster *tmp = *wave;

    if (game->play.life <= 0)
        end_game(game, 0);
    if (game->data.wave > 10)
        end_game(game, 1);
    while (tmp) {
        if (tmp->draw.pos.x > 1920 * game->data.scale_img.x) {
            tmp->alive = 0;
            game->play.life -= tmp->damage;
        } else if (tmp->life <= 0) {
            sfMusic_play(game->play.music[2]);
            game->data.gold += 20;
            tmp->alive = 0;
        }
        tmp = tmp->next;
    }
    delete_mob_dead(wave, game);
}
