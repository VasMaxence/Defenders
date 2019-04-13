/*
** EPITECH PROJECT, 2019
** graph
** File description:
** src/menu/option/data/data_option.c
*/

#include "my_defenders.h"

void set_img_settings(s_defenders *game)
{
    FILE *fp = fopen("config/settings/img.fpc", "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return;
    for (int i = 0; i < 25; i++) {
        if (getline(&line, &len, fp) == -1)
            return;
        line[my_strlen(line) - 1] = '\0';
        game->settings.draw[i].sprite = sfSprite_create();
        game->settings.draw[i].texture = sfTexture_createFromFile(line, NULL);
        sfSprite_setTexture(game->settings.draw[i].sprite,
        game->settings.draw[i].texture, sfTrue);
        sfSprite_setScale(game->settings.draw[i].sprite, game->data.scale_img);
    }
    free(line);
    fclose(fp);
}

void set_text_settings(s_defenders *game)
{
    FILE *fp = fopen("config/settings/text.fpc", "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return;
    for (int i = 0; i < 6; i++) {
        if (getline(&line, &len, fp) == -1)
            return;
        game->settings.text[i].text = sfText_create();
        sfText_setString(game->settings.text[i].text, line);
        sfText_setColor(game->settings.text[i].text, sfWhite);
        sfText_setCharacterSize(game->settings.text[i].text,
        50 * game->data.scale_img.x);
        sfText_setFont(game->settings.text[i].text, game->data.font);
    }
    free(line);
    fclose(fp);
}

void set_img_pos_settings(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img = sfTexture_getSize(game->settings.draw[0].texture);
    size_img.x *= game->data.scale_img.x;
    size_img.y *= game->data.scale_img.y;

    game->settings.draw[0].pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->settings.draw[0].pos.y = (size_window.y / 2) - (size_img.y / 2);
    sfSprite_setPosition(game->settings.draw[0].sprite,
    game->settings.draw[0].pos);
    set_pos_decor_settings(game, size_window);
    set_pos_rod_settings(game, size_window);
    set_settings_audio_pos(game, size_window);
}

void set_settings(s_defenders *game)
{
    sfVector2u size_window = sfRenderWindow_getSize(game->window);
    sfVector2u size_img;

    set_img_settings(game);
    set_text_settings(game);
    set_img_pos_settings(game);
    game->settings.alert.texture =
    sfTexture_createFromFile("ressources/settings/alert.png", NULL);
    size_img = get_size_img(game->settings.alert.texture, game->data.scale_img);
    game->settings.alert.sprite = sfSprite_create();
    sfSprite_setTexture(game->settings.alert.sprite,
    game->settings.alert.texture, sfTrue);
    sfSprite_setScale(game->settings.alert.sprite, game->data.scale_img);
    game->settings.alert.pos.x = (size_window.x / 2) - (size_img.x / 2);
    game->settings.alert.pos.y = (size_window.y / 2) - (size_img.y / 2);
    sfSprite_setPosition(game->settings.alert.sprite,
    game->settings.alert.pos);
}

sfVector2u get_size_img(sfTexture *texture, sfVector2f scale_img)
{
    sfVector2u size_img = sfTexture_getSize(texture);

    size_img.x *= scale_img.x;
    size_img.y *= scale_img.y;
    return (size_img);
}
