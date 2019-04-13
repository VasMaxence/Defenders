/*
** EPITECH PROJECT, 2018
** my_defenders
** File description:
** list
*/

#include "my_defenders.h"

void open_wave(s_data_monster *data, char *path)
{
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != - 1) {
        if (my_strcmp(line, "  nb_monster:") == 13)
            data->nb_monster = init_value(line, len, fp, data->nb_monster);
        if (my_strcmp(line, "  basic monster:") == 16)
            data->basic_m = init_value(line, len, fp, data->basic_m);
        if (my_strcmp(line, "  speed monster:") == 16)
            data->speed_m = init_value(line, len, fp, data->speed_m);
        if (my_strcmp(line, "  big monster:") == 14)
            data->big_m = init_value(line, len, fp, data->big_m);
    }
    free(line);
    fclose(fp);
}

int init_value(char *line, size_t len, FILE *fp, int monster)
{
    getline(&line, &len, fp);
    monster = my_getnbr(line);
    return (monster);
}

s_sprite set_texture_mob(char *path)
{
    s_sprite ret;

    ret.sprite = sfSprite_create();
    ret.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(ret.sprite, ret.texture, sfTrue);
    return (ret);
}

void open_wave_basic(s_monster **import, char *path)
{
    s_monster *mob = *import;
    FILE *fp = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != - 1) {
        if (my_strcmp(line, "  life:") == 7)
            mob->life = init_carac(line, len, fp, mob->life);
        else if (my_strcmp(line, "  damage") == 8)
            mob->damage = init_carac(line, len, fp, mob->damage);
        else if (my_strcmp(line, "  speed") == 7)
            mob->speed = init_carac(line, len, fp, mob->speed);
        if (my_strcmp(line, "  walking animation:") == 20) {
            getline(&line, &len, fp);
            line[my_strlen(line) - 1] = '\0';
            mob->draw = set_texture_mob(line);
        } else if (my_strcmp(line, "  type:") == 7)
            mob->type = init_carac(line, len, fp, mob->type);
    }
    fclose(fp);
}

int init_carac(char *line, size_t len, FILE *fp, int data)
{
    getline(&line, &len, fp);
    data = my_getnbr(line);
    return (data);
}
