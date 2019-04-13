/*
** EPITECH PROJECT, 2019
** graph
** File description:
** prototype.h
*/

#ifndef _H_PROTOTYPE_
#define _H_PROTOTYPE_

#include "my_defenders.h"

//MAIN FOLDERS: ROOT
//Folders:      src/
//File:         main.c
int play_game(void);
void launch_intro(s_defenders *);

//Folders:      src/data/
//File:         data_game.c
int set_value_from_file(char *, int *);
int set_data_game(s_defenders *);
int verif_data_window(s_defenders *);
int set_font(s_defenders *);
void set_music_menu(s_defenders *);

//MAIN FOLDERS: MENU
//Folders:      src/menu/
//File:         menu.c
void launch_menu(s_defenders *);
void play_menu(s_defenders *);
void close_window(s_defenders *, sfEvent *);
void destroy_menu(s_defenders *);
void check_event_menu(s_defenders *, sfEvent *);

//Folders:      src/menu/data/
//File:         data_menu.c
int set_img_menu(s_defenders *, char *);
int set_data_menu(s_defenders *);
void set_pos_menu(s_defenders *);
void set_pos_menu_button(s_defenders *);

//Folders:      src/menu/event/
//File:         mouse_on_button.c
void mouse_pos_on_button(s_defenders *, sfEvent *);
sfIntRect set_rect_from_sprite(s_sprite, sfVector2f);
void choose_button_with_keypad(s_defenders *, sfEvent *);

//File:         action_button_menu.c
void event_of_enter_menu(s_defenders *, sfEvent *);
void event_of_button_menu(s_defenders *, sfEvent *);

//Folders:      src/menu/parallax/
//File:         parralax.c
void parralax_menu(s_defenders *);
void parralax_one(s_defenders *);
void fix_pos_one(s_defenders *);

//File:         parralax_part1.c
void parralax_two(s_defenders *);
void fix_pos_two(s_defenders *);
void parralax_three(s_defenders *);
void fix_pos_three(s_defenders *);

//File:         parralax_part2.c
void parralax_four(s_defenders *);
void fix_pos_four(s_defenders *);
void parralax_five(s_defenders *);
void fix_pos_five(s_defenders *);

//File:         parralax_part3.c
void parralax_six(s_defenders *);
void fix_pos_six(s_defenders *);
void parralax_seven(s_defenders *);
void fix_pos_seven(s_defenders *);

//MAIN FOLDERS: SETTINGS
//Folders:      src/menu/option/
//File:         option.c
void launch_settings(s_defenders *, sfEvent *);
void play_settings(s_defenders *, sfEvent *);
void destroy_settings(s_defenders *);
void draw_music_settings(s_defenders *);

//Folders:      src/menu/option/data/
//File:         data_options.c
void set_settings(s_defenders *);
void set_img_settings(s_defenders *);
sfVector2u get_size_img(sfTexture *, sfVector2f);

//File:         data_pos_settings.c
void set_pos_decor_settings(s_defenders *, sfVector2u);
void set_pos_rod_settings(s_defenders *, sfVector2u);
void set_settings_audio_pos(s_defenders *, sfVector2u);
void set_music_audio(s_defenders *, sfVector2u);

//File:         data_pos_settings2.c
void set_effect_music(s_defenders *, sfVector2u);
int set_pos_text_audio(s_defenders *, sfVector2u);

//File:         settings_graph.c
void set_pos_graph_settings(s_defenders *, sfVector2u);
void set_pos_text_graph(s_defenders *, sfVector2u);
char *set_text_size(s_defenders *);
void print_line_tilemapping(char *, sfVector2f, s_defenders *);

//Folders:      src/menu/option/event/
//File:         event_settings.c
int event_settings_check(s_defenders *, sfEvent *);
void resize_all(s_defenders *);

//MAIN FOLDERS: GAME
//Folders:      src/game/
//File:         file.c
void launch_play(s_defenders *, sfEvent *);
void play_play(s_defenders *, sfEvent *);

//Folders:      src/game/data/
//File:         data_tileset.c
void set_data_tilset(s_defenders *, char *);

//File:         data_tilemapping.c
void set_tilemapping(s_defenders *, char *);

//File:         utils_tilemapping.c
int nb_line_on_map(char *);
char *my_strdup(char *);

//File:         data_game.c
void set_data_play(s_defenders *);

//File:         data_overlay.c
void set_data_overlay(s_defenders *);

//Folders:      src/game/pause/data/
//File:         set_data_pause.c
void set_data_pause(s_defenders *);
void set_texture_pause(s_defenders *, char *);
void set_text_pause(s_defenders *, char *);
void set_pos_pause(s_defenders *);
void set_equa_pause_button(s_defenders *, sfVector2u, sfVector2u, sfVector2u);

//File:         data_pause2.c
void set_text_pause_pos(s_defenders *);

//Folders:      src/game/pause/
//File:         pause.c
void play_pause(s_defenders *, sfEvent *);
void destroy_pause(s_defenders *);

//Folders:      src/game/pause/event/
//File:         event_pause_button.c
void check_event_button_pause(s_defenders *, sfEvent *);
void resume_game(s_defenders *, sfEvent *);
void return_menu_from_pause(s_defenders *, sfEvent *);

//MAIN FOLDERS: src/shop/
//Folders:      shop/
//File:         shop.c
void play_shop(s_defenders *, sfEvent *);
void launch_shop(s_defenders *, sfEvent *);
void destroy_shop(s_defenders *);

//Folders:      data/
//File:         data_shop.c
int set_data_shop(s_defenders *);
void set_pos_texture_shop(s_defenders *);
void set_texture_shop(s_defenders *);
void set_skill_level(s_defenders *, char *);
char *take_nbr(char *);

//File:         data_text_shop.c
void set_nb_skill(s_defenders *, char *);
void set_text_shop(s_defenders *);

//File:         data_shop_pos.c
void pos_window_shop(s_defenders *, sfVector2u);

//Folders:      event/
//File:         event_skill.c
void event_up_skill(s_defenders *, sfEvent *);

void load_defense(s_defenders *);

void set_data_tower(s_defenders *);
void check_event_tower(s_defenders *, sfEvent *);
void set_text_gold(s_defenders *);
void chekc_clock_gold(s_defenders *);
void print_map(s_defenders *);
void set_data_archer(s_defenders *);
void event_archer(s_defenders *, sfEvent *, sfIntRect);
void launch_tutorial(s_defenders *);
void set_data_tutorial(s_defenders *);
void page_up(s_defenders *);
void page_down(s_defenders *);
s_data_monster *add_monster(char *, s_defenders *);
void open_wave(s_data_monster *, char *);
int init_value(char *, size_t, FILE *, int);
void open_wave_basic(s_monster **, char *);
int init_carac(char *, size_t, FILE *, int);
void delete_middle(s_monster **);
void delete_end(s_monster **);
void delete_begin(s_monster **);
void add_begin(s_monster **, int);
void add_end(s_monster **, char *);
void set_rect_mob(s_monster **, s_defenders *);
void draw_mob(s_monster **, s_defenders *);
void check_mob_on_map(s_monster **, s_defenders *);
void tower_vs_mob(s_defenders *);
void draw_attack_tower(s_defenders *);
void archer_vs_mob(s_defenders *);
void event_overlay(s_defenders *, sfEvent *);
void check_attack_fireball(s_defenders *, s_monster **);
void event_fireball(s_defenders *, sfEvent *);
void set_data_spell(s_defenders *);
void check_new_wave(s_defenders *, s_monster **);
void add_new_wave(s_monster **, s_defenders *);
void set_sound_play(s_defenders *);
void set_sound_tuto(s_defenders *);
void print_wave(s_defenders *);
void end_game(s_defenders *, int);
void event_button_end(s_defenders *, sfEvent *);
void set_text_end(s_defenders *, int);

#endif /*_H_PROTOTYPE_*/
