/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/game/play.c
*/

#include "my_defenders.h"

void launch_play(s_defenders *game, sfEvent *event)
{
    game->play.bool = 1;
    game->play.bool_menu = 0;
    game->pause.draw = malloc(sizeof(struct t_sprite) * 4);
    game->pause.text = malloc(sizeof(struct t_text) * 3);
    game->data.gold = 300;
    game->data.clock_gold = sfClock_create();
    set_text_gold(game);
    set_sound_play(game);
    set_data_tilset(game, "config/tileset.fpc");
    set_data_pause(game);
    set_tilemapping(game, "config/map/map1.fpc");
    set_data_play(game);
    load_defense(game);
    for (int i = 0; i < 4; i++)
        game->defense.tower[i].clock = sfClock_create();
    game->play.life = 300;
    game->play.wave = add_monster("config/wave/wave_1.fpc", game);
    set_rect_mob(&game->play.wave->monster, game);
    sfMusic_play(game->play.music[0]);
    play_play(game, event);
}

void print_map(s_defenders *game)
{
    int i = -1;
    sfVector2f pos = {0, 0};

    while (game->play.tilemapping.map[++i]) {
        print_line_tilemapping(game->play.tilemapping.map[i], pos, game);
        pos.y += (128 * game->data.scale_img.y);
    }
}

void destroy_game(s_defenders *game)
{
    for (int i = 0; i < 15; i++) {
        sfSprite_destroy(game->play.overlay.draw[i].sprite);
        sfTexture_destroy(game->play.overlay.draw[i].texture);
    }
    for (int i = 0; i < 3; i++)
        sfMusic_destroy(game->play.music[i]);
    free(game->play.music);
    free(game->play.overlay.draw);
}

void draw_overlay(s_defenders *game)
{
    sfRenderWindow_drawSprite(game->window, game->tileset[0].sprite, NULL);
    print_map(game);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window,
        game->defense.tower[i].draw.sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(game->window,
        game->defense.archer[i].draw.sprite, NULL);
    sfRenderWindow_drawText(game->window, game->data.text_gold, NULL);
    draw_mob(&game->play.wave->monster, game);
    tower_vs_mob(game);
    draw_attack_tower(game);
    archer_vs_mob(game);
    print_wave(game);
    check_mob_on_map(&game->play.wave->monster, game);
    for (int i = 0; i < 15; i++)
        sfRenderWindow_drawSprite(game->window,
        game->play.overlay.draw[i].sprite, NULL);
    chekc_clock_gold(game);
    check_new_wave(game, &game->play.wave->monster);
}

void play_play(s_defenders *game, sfEvent *event)
{
    destroy_menu(game);
    while (sfRenderWindow_isOpen(game->window) && game->play.bool) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_overlay(game);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            event_fireball(game, event);
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(game->window);
            if (event->type == sfEvtKeyPressed
            && event->key.code == sfKeyEscape)
                play_pause(game, event);
            check_event_tower(game, event);
            event_overlay(game, event);
        }
    }
    destroy_pause(game);
    destroy_game(game);
    if (game->play.bool_menu)
        launch_menu(game);
}
