/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** end_game.c
*/

#include "my_defenders.h"

void event_end(s_defenders *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            game->play.end.bool = 0;
        event_button_end(game, &event);
    }
}

void play_end(s_defenders *game)
{
    while (sfRenderWindow_isOpen(game->window) && game->play.end.bool) {
        sfRenderWindow_clear(game->window, sfBlack);
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawSprite(game->window,
            game->play.end.draw[i].sprite, NULL);
        sfRenderWindow_drawText(game->window,
        game->play.end.text.text, NULL);
        sfRenderWindow_display(game->window);
        event_end(game);
    }
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(game->play.end.draw[i].sprite);
        sfTexture_destroy(game->play.end.draw[i].texture);
    }
    free(game->play.end.draw);
}

void set_pos_end(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);

    game->play.end.draw[0].pos.x = 0;
    game->play.end.draw[0].pos.y = 0;
    game->play.end.draw[1].pos.x = size_window.x / 2
    - (639 / 2 * game->data.scale_img.x);
    game->play.end.draw[1].pos.y = size_window.y / 2
    - (809 / 2 * game->data.scale_img.x);
    game->play.end.draw[2].pos.x = size_window.x / 2
    - (186 * game->data.scale_img.x);
    game->play.end.draw[2].pos.y = size_window.y / 4 * 3;
    game->play.end.draw[3].pos.x = size_window.x / 2
    + (10 + game->data.scale_img.x);
    game->play.end.draw[3].pos.y = size_window.y / 4 * 3;
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(game->play.end.draw[3].sprite,
        game->play.end.draw[3].pos);
}

void set_end(s_defenders *game, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    for (int i = 0; i < 4; i++) {
        getline(&line, &len, fp);
        line[my_strlen(line) - 1] = '\0';
        game->play.end.draw[i].sprite = sfSprite_create();
        game->play.end.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->play.end.draw[i].sprite,
        game->play.end.draw[i].texture, sfTrue);
    }
    free(line);
    fclose(fp);
    set_pos_end(game);
}

void end_game(s_defenders *game, int i)
{
    game->play.end.draw = malloc(sizeof(s_sprite) * 4);
    set_end(game, "config/end.fpc");
    set_text_end(game, i);
    game->play.end.bool = 1;
    play_end(game);
}
