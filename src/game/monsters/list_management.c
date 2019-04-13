/*
** EPITECH PROJECT, 2018
** my_defenders
** File description:
** list_management
*/

#include "my_defenders.h"

void add_end(s_monster **mob, char *path)
{
    s_monster *node;
    s_monster *tmp;

    node = malloc(sizeof(s_monster));
    open_wave_basic(&node, path);
    node->anim = sfClock_create();
    tmp = *mob;
    node->next = NULL;
    node->prev = NULL;
    if (*mob == NULL)
        *mob = node;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
        node->prev = tmp;
    }
}

void delete_begin(s_monster **monster)
{
    if (*monster != NULL && (*monster)->next != NULL) {
        *monster = (*monster)->next;
    } else
        *monster = NULL;
}

void delete_end(s_monster **monster)
{
    s_monster *tmp;

    if (*monster != NULL) {
        tmp = (*monster);
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
    } else
        (*monster) = NULL;
}

void delete_middle(s_monster **monster)
{
    s_monster *tmp;

    if (!((*monster)->alive)) {
        tmp = (*monster);
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
    } else
        (*monster) = NULL;
}
