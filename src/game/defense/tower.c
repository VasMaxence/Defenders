/*
** EPITECH PROJECT, 2019
** MUL_my_defenders_2018
** File description:
** set_data_tower.c
*/

#include "my_defenders.h"

void set_hitbox_tower(s_tower *ret)
{
    sfVector2u size_img = sfTexture_getSize(ret->draw.texture);

    ret->shoot_bool = 0;
    ret->hit_tower.left = 0;
    ret->hit_tower.top = 0;
    ret->hit_tower.width = size_img.x / 3;
    ret->hit_tower.height = size_img.y;
    size_img = sfTexture_getSize(ret->animated.texture);
    ret->hit_animate.left = 0;
    ret->hit_animate.top = 0;
    ret->hit_animate.width = size_img.x / 2;
    ret->hit_animate.height = size_img.y;
    ret->clock = sfClock_create();
    sfSprite_setTextureRect(ret->draw.sprite, ret->hit_tower);
    sfSprite_setTextureRect(ret->animated.sprite, ret->hit_animate);
}

s_sprite set_tower_animated(char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    s_sprite ret;

    while (getline(&line, &len, fp) != -1) {
        if (my_strcmp(line, "  animate:") == 10) {
            getline(&line, &len, fp);
            line[my_strlen(line) - 1] = '\0';
            ret.sprite = sfSprite_create();
            ret.texture = sfTexture_createFromFile(line, NULL);
            sfSprite_setTexture(ret.sprite, ret.texture, sfTrue);
        }
    }
    free(line);
    fclose(fp);
    return (ret);
}

s_sprite set_tower_skin(char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    s_sprite ret;

    while (getline(&line, &len, fp) != -1) {
        if (my_strcmp(line, "  skin:") == 7) {
            getline(&line, &len, fp);
            line[my_strlen(line) - 1] = '\0';
            ret.sprite = sfSprite_create();
            ret.texture = sfTexture_createFromFile(line, NULL);
            sfSprite_setTexture(ret.sprite, ret.texture, sfTrue);
        }
    }
    free(line);
    fclose(fp);
    return (ret);
}

struct t_tower set_tower(char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    struct t_tower ret;

    while (getline(&line, &len, fp) != -1) {
        if (my_strcmp(line, "  damage:") == 9) {
            getline(&line, &len, fp);
            ret.damage = my_getnbr(line);
        } else if (my_strcmp(line, "  range:") == 8) {
            getline(&line, &len, fp);
            ret.range = my_getnbr(line);
        } else if (my_strcmp(line, "  AS:") == 5) {
            getline(&line, &len, fp);
            ret.attack_speed = my_getnbr(line);
        }
        ret.draw = set_tower_skin(path);
        ret.animated = set_tower_animated(path);
        set_hitbox_tower(&ret);
    }
    free(line);
    fclose(fp);
    return (ret);
}

void set_data_tower(s_defenders *game)
{
    game->defense.tower = malloc(sizeof(struct t_tower) * 4);
    game->defense.tower[0] = set_tower("config/defense/magictower_blue.fpc");
    game->defense.tower[1] = set_tower("config/defense/magictower_green.fpc");
    game->defense.tower[2] = set_tower("config/defense/magictower_red.fpc");
    game->defense.tower[3] = set_tower("config/defense/magictower_yellow.fpc");
    for (int i = 0; i < 4; i++)
        sfSprite_setScale(game->defense.tower[i].draw.sprite,
        game->data.scale_img);
}
