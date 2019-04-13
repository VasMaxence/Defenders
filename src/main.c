/*
** EPITECH PROJECT, 2019
** graph
** File description:
** main.c for my_defenders
*/

#include "include/my_defenders.h"

int main(int ac, char **av)
{
    if (play_game()) {
        write(2, "Error: pls re-clone the game.\n", 30);
        return (84);
    }
    return (1);
}

int play_game(void)
{
    s_defenders *game = malloc(sizeof(struct t_defenders));

    if (set_data_game(game)) {
        free(game);
        return (1);
    }
    if (set_font(game)) {
        free(game);
        return (1);
    }
    launch_intro(game);
    launch_menu(game);
    sfRenderWindow_destroy(game->window);
    free(game);
    return (0);
}
