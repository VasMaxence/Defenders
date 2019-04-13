/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** spell.c
*/

#include "my_defenders.h"

void check_attack_fireball(s_defenders *game, s_monster **wave)
{
    sfIntRect hitbox = set_rect_from_sprite(game->defense.spell->draw,
    game->data.scale_img);
    sfIntRect hitbox_mob = {0};
    s_monster *tmp = *wave;

    while (tmp) {
        hitbox_mob = set_rect_from_sprite(tmp->draw, game->data.scale_img);
        if (sfIntRect_intersects(&hitbox, &hitbox_mob, NULL) == sfTrue) {
            tmp->life -= game->defense.spell->damage;
        }
        tmp = tmp->next;
    }
}

void event_fireball(s_defenders *game, sfEvent *event)
{
    sfVector2u size_img = sfTexture_getSize(game->defense.spell->draw.texture);

    if (event->type == sfEvtMouseButtonPressed
    && game->defense.spell->waiting && game->data.gold) {
        size_img.x /= 19;
        game->data.gold -= 300;
        game->defense.spell->rect.left = 0;
        game->defense.spell->using = 1;
        game->defense.spell->draw.pos.x = event->mouseButton.x - size_img.x / 2;
        game->defense.spell->draw.pos.y = event->mouseButton.y - size_img.y;
        sfSprite_setTextureRect(game->defense.spell->draw.sprite,
        game->defense.spell->rect);
        sfSprite_setPosition(game->defense.spell->draw.sprite,
        game->defense.spell->draw.pos);
        check_attack_fireball(game, &game->play.wave->monster);
    }
}

void use_fireball(s_defenders *game, int i)
{
    game->defense.spell->waiting = 1;
}

void second_set_fireball(s_defenders *game)
{
    game->defense.spell->anim_clock = sfClock_create();
    game->defense.spell->reload_clock = sfClock_create();
    game->defense.spell->using = 0;
    game->defense.spell->damage = 48;
    game->defense.spell->time_reload = 800;
    game->defense.spell->waiting = 0;
}

void set_data_spell(s_defenders *game)
{
    sfVector2u size_img = {0};

    game->defense.spell = malloc(sizeof(struct t_spell) * 1);
    game->defense.spell->draw.sprite = sfSprite_create();
    game->defense.spell->draw.texture = sfTexture_createFromFile(
    "ressources/defense/magic/spell_fireball.png", NULL);
    sfSprite_setTexture(game->defense.spell->draw.sprite,
    game->defense.spell->draw.texture, sfTrue);
    size_img = sfTexture_getSize(game->defense.spell->draw.texture);
    game->defense.spell->rect.left = 0;
    game->defense.spell->rect.top = 0;
    game->defense.spell->rect.width = size_img.x / 19;
    game->defense.spell->rect.height = size_img.y;
    sfSprite_setTextureRect(game->defense.spell->draw.sprite,
    game->defense.spell->rect);
    game->defense.spell->draw.pos.x = 0;
    game->defense.spell->draw.pos.y = 0;
    second_set_fireball(game);
}
