##
## EPITECH PROJECT, 2018
## src
## File description:
## Makefile for my_hunter
##

COLOR = 		/bin/echo -e

DEFAULT =		'\033[0m'
RED =			'\033[31m'
GREEN =			'\033[32m'
YELLOW =		'\033[33m'
BLUE =			'\033[34m'
PURPLE =		"\033[35m"
CYAN =			"\033[36m"
WHITE =			"\033[37m"
BLACK = 		"\033[30m"
ERROR = 		"\033[5m"
UNDERLINE =		"\033[4m"
ITALIQUE =		"\033[3m"
BOLD =	 		"\033[1m"

ECH =	echo ""

TEST = 		unit_test

SRC_TEST =		tests/test_data_game.c \
src/intro.c \
src/data/data_game.c \
$(MENU)/menu.c \
$(MENU)/data/data_menu.c \
$(MENU)/event/mouse_on_button.c \
$(MENU)/event/action_button_menu.c \
$(MENU)/parallax/parralax.c \
$(MENU)/parallax/parralax_part1.c \
$(MENU)/parallax/parralax_part2.c \
$(MENU)/parallax/parralax_part3.c \
$(OPTION)/option.c \
$(OPTION)/event/event_settings.c \
$(OPTION)/event/event_graph.c \
$(OPTION)/event/fct_event_settings.c \
$(OPTION)/data/data_options.c \
$(OPTION)/data/settings_graph.c \
$(OPTION)/data/data_pos_settings.c \
$(OPTION)/data/data_pos_settings2.c \
$(PLAY)/play.c \
$(PLAY)/end_game.c \
$(PLAY)/event_end.c \
$(PLAY)/new_wave.c \
$(PLAY)/tower_attack.c \
$(PLAY)/tower_and_mob_is_love.c \
$(PLAY)/archer_and_mob_is_love.c \
$(PLAY)/overlay.c \
$(PLAY)/data/data_sound.c \
$(PLAY)/data/data_game.c \
$(PLAY)/data/data_overlay.c \
$(PLAY)/data/data_tilset.c \
$(PLAY)/data/data_tilemapping.c \
$(PLAY)/data/utils_tilemapping.c \
$(PLAY)/pause/data/set_data_pause.c\
$(PLAY)/pause/data/data_pause2.c\
$(PLAY)/pause/event/event_pause_button.c \
$(PLAY)/pause/pause.c \
$(PLAY)/monsters/add_monster.c \
$(PLAY)/monsters/monsters.c \
$(PLAY)/monsters/mob_alive.c \
$(PLAY)/monsters/draw_mob.c \
$(PLAY)/monsters/set_texture_monster.c \
$(PLAY)/monsters/list_management.c \
$(SHOP)/shop.c \
$(SHOP)/data/data_shop.c \
$(SHOP)/data/data_text_shop.c \
$(SHOP)/data/data_shop_pos.c \
$(SHOP)/event/event_skill.c \
$(DEF)/load_defense.c \
$(DEF)/tower.c \
$(DEF)/spell.c \
$(DEF)/archer.c \
$(DEF)/event/event_defense.c \
$(DEF)/event/event_archer.c \
$(TUTO)/tutorial.c \
$(TUTO)/event_tutorial.c \
$(TUTO)/data/data_tutorial.c \

INC =			-I./src/include

MAKE = 			make --no-print-directory

MENU =				src/menu

OPTION =			src/menu/option

PLAY =				src/game

SHOP =				src/shop

DEF = 				src/game/defense

TUTO =				src/menu/tutorial

SRC =				src/main.c \
					src/intro.c \
					src/data/data_game.c \
					$(MENU)/menu.c \
					$(MENU)/data/data_menu.c \
					$(MENU)/event/mouse_on_button.c \
					$(MENU)/event/action_button_menu.c \
					$(MENU)/parallax/parralax.c \
					$(MENU)/parallax/parralax_part1.c \
					$(MENU)/parallax/parralax_part2.c \
					$(MENU)/parallax/parralax_part3.c \
					$(OPTION)/option.c \
					$(OPTION)/event/event_settings.c \
					$(OPTION)/event/event_graph.c \
					$(OPTION)/event/fct_event_settings.c \
					$(OPTION)/data/data_options.c \
					$(OPTION)/data/settings_graph.c \
					$(OPTION)/data/data_pos_settings.c \
					$(OPTION)/data/data_pos_settings2.c \
					$(PLAY)/play.c \
					$(PLAY)/end_game.c \
					$(PLAY)/event_end.c \
					$(PLAY)/new_wave.c \
					$(PLAY)/tower_attack.c \
					$(PLAY)/tower_and_mob_is_love.c \
					$(PLAY)/archer_and_mob_is_love.c \
					$(PLAY)/overlay.c \
					$(PLAY)/data/data_sound.c \
					$(PLAY)/data/data_game.c \
					$(PLAY)/data/data_overlay.c \
					$(PLAY)/data/data_tilset.c \
					$(PLAY)/data/data_tilemapping.c \
					$(PLAY)/data/utils_tilemapping.c \
					$(PLAY)/pause/data/set_data_pause.c\
					$(PLAY)/pause/data/data_pause2.c\
					$(PLAY)/pause/event/event_pause_button.c \
					$(PLAY)/pause/pause.c \
					$(PLAY)/monsters/add_monster.c \
					$(PLAY)/monsters/monsters.c \
					$(PLAY)/monsters/mob_alive.c \
					$(PLAY)/monsters/draw_mob.c \
					$(PLAY)/monsters/set_texture_monster.c \
					$(PLAY)/monsters/list_management.c \
					$(SHOP)/shop.c \
					$(SHOP)/data/data_shop.c \
					$(SHOP)/data/data_text_shop.c \
					$(SHOP)/data/data_shop_pos.c \
					$(SHOP)/event/event_skill.c \
					$(DEF)/load_defense.c \
					$(DEF)/tower.c \
					$(DEF)/spell.c \
					$(DEF)/archer.c \
					$(DEF)/event/event_defense.c \
					$(DEF)/event/event_archer.c \
					$(TUTO)/tutorial.c \
					$(TUTO)/event_tutorial.c \
					$(TUTO)/data/data_tutorial.c \

GCC =				gcc

OBJ =				$(SRC:.c=.o)

LIB = 				-L./lib/ -lmy

LGRAPH =			-L./lib/ -lgraph

COMPILLIB =			$(MAKE) -C lib/my/ all

CLEANLIB = 			$(MAKE) -C lib/my/ fclean

CSFML =				-l csfml-graphics -l csfml-audio -l csfml-network -l csfml-system -l csfml-window

NAME = 				my_defenders

all:				host $(NAME) clean

test_run:			fclean_test $(TEST) clean_test

host :
					@$(COLOR) $(CYAN) $(UNDERLINE) $(BOLD) "Program Compilation:" $(DEFAULT) $(YELLOW) $(ITALIQUE) "  $(NAME)" $(DEFAULT)
					@echo ""
					@$(COLOR) $(YELLOW) "***************************" $(DEFAULT)
					@$(COLOR) $(YELLOW) "* CREATION SRC .o : START *" $(DEFAULT)
					@$(COLOR) $(YELLOW) "***************************" $(DEFAULT)
					@$(ECH)

$(NAME):			$(OBJ)
					@$(ECH)
					@$(COLOR) $(GREEN) "******************************" $(DEFAULT)
					@$(COLOR) $(GREEN) "* CREATION SRC .o : TERMINEE *" $(DEFAULT)
					@$(COLOR) $(GREEN) "******************************" $(DEFAULT)
					@$(ECH)
					@$(COLOR) $(YELLOW) "******************************" $(DEFAULT)
					@$(COLOR) $(YELLOW) "* CREATION LIBRAIRIE : START *" $(DEFAULT)
					@$(COLOR) $(YELLOW) "******************************" $(DEFAULT)
					@$(ECH)
					@$(COMPILLIB)
					@$(COLOR) $(YELLOW) "***************************" $(DEFAULT)
					@$(COLOR) $(YELLOW) "* COMPILATION SRC : START *" $(DEFAULT)
					@$(COLOR) $(YELLOW) "***************************" $(DEFAULT)
					@$(ECH)
					@$(GCC) $(SRC) -o $(NAME) $(CSFML) $(LIB) $(INC) -g3 && \
					$(CLEANLIB) && \
					$(COLOR) $(GREEN) "******************************" $(DEFAULT) && \
					$(COLOR) $(GREEN) "* COMPILATION SRC : TERMINEE *" $(DEFAULT) && \
					$(COLOR) $(GREEN) "******************************" $(DEFAULT) || \
					$(COLOR) $(RED) $(ERROR) "* COMPILATION SRC : CRASH *" $(DEFAULT)
					@$(ECH)
					@$(COLOR) $(GREEN) $(BOLD) "****************************" $(DEFAULT)
					@$(COLOR) $(GREEN) $(BOLD) "*    " $(UNDERLINE) "MAKEFILE" $(DEFAULT) $(GREEN) $(BOLD) ": END   *" $(DEFAULT)
					@$(COLOR) $(GREEN) $(BOLD) "****************************" $(DEFAULT)
					@$(ECH)


$(TEST):
					@$(ECH)
					@$(COLOR) $(YELLOW) "******************************" $(DEFAULT)
					@$(COLOR) $(YELLOW) "* CREATION LIBRAIRIE : START *" $(DEFAULT)
					@$(COLOR) $(YELLOW) "******************************" $(DEFAULT)
					@$(ECH)
					@$(COMPILLIB)
					@$(COLOR) $(YELLOW) "*********************************" $(DEFAULT)
					@$(COLOR) $(YELLOW) "* COMPILATION UNIT TEST : START *" $(DEFAULT)
					@$(COLOR) $(YELLOW) "*********************************" $(DEFAULT)
					@$(ECH)
					@$(GCC) $(SRC_TEST) -o $(TEST) $(CSFML) $(LIB) $(INC) --coverage -lcriterion -g3 && \
					$(CLEANLIB) && \
					$(COLOR) $(GREEN) "************************************" $(DEFAULT) && \
					$(COLOR) $(GREEN) "* COMPILATION UNIT TEST : TERMINEE *" $(DEFAULT) && \
					$(COLOR) $(GREEN) "************************************" $(DEFAULT) || \
					$(COLOR) $(RED) $(ERROR) "* COMPILATION SRC : CRASH *" $(DEFAULT)
					@$(ECH)
					@$(COLOR) $(GREEN) $(BOLD) "****************************" $(DEFAULT)
					@$(COLOR) $(GREEN) $(BOLD) "*    " $(UNDERLINE) "MAKEFILE" $(DEFAULT) $(GREEN) $(BOLD) ": END   *" $(DEFAULT)
					@$(COLOR) $(GREEN) $(BOLD) "****************************" $(DEFAULT)
					@$(ECH)

%.o : %.c
					@$(GCC) -c -o $@ $< $(CSFML) $(INC) && \
					$(COLOR) $(GREEN) "[OK] : " $(PURPLE) $(BOLD) $< $(DEFAULT) || \
					$(COLOR) $(RED) $(ERROR) "[KO] : " $(DEFAULT) $(YELLOW) $< $(DEFAULT)

clean_test:
					@rm -rf *.gc*

fclean_test:		clean_test
					@rm -rf $(TEST) && \
					$(COLOR) $(GREEN) "***********************************" $(DEFAULT) && \
					$(COLOR) $(GREEN) "* SUPPRESSION UNIT TEST :TERMINEE *" $(DEFAULT) && \
					$(COLOR) $(GREEN) "***********************************" $(DEFAULT)

clean:
					@$(CLEANLIB)
					@rm -rf $(OBJ)

fclean:				clean
					@rm -rf $(NAME) && \
					$(COLOR) $(GREEN) "*********************************" $(DEFAULT) && \
					$(COLOR) $(GREEN) "* SUPPRESSION PROGRAM :TERMINEE *" $(DEFAULT) && \
					$(COLOR) $(GREEN) "*********************************" $(DEFAULT)

re:					fclean all clean

re_test:			fclean_test test_run clean_test
