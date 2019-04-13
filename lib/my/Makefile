##
## EPITECH PROJECT, 2018
## LIB
## File description:
## Makefile LIB
##

ECHO = 		echo -e

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

SRC = 	my_isneg.c \
		my_verif_open.c \
		my_nb_to_str.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		print_usage.c \
		my_value.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_is_prime.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_sort_in_array.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strcapitalize.c \
		my_strcat.c \
		arg_flags.c \
		arg_flags3.c \
		arg_flags2.c \
		my_strncat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strl.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncpy.c \
		my_strstr.c \
		my_strncmp.c \
		my_strupcase.c \
		my_swap.c \
		my_printf.c \
		my_flags.c \
		my_flags2.c \
		my_flags3.c \
		my_flags4.c

ECH =	echo ""

COMPIL = $(SRC:.c=.o)

GCC = 	gcc

AR = ar rc

NAME = libmy.a

all: 				$(NAME) clean

$(NAME): 			$(COMPIL)
					@$(ECH)
					@ar rc $(NAME) $(COMPIL) && \
					cp $(NAME) ../ && \
					$(ECHO) $(GREEN) "********************************" $(DEFAULT) && \
					$(ECHO) $(GREEN) "* CREATION LIBRAIRIE :TERMINEE *" $(DEFAULT) && \
					$(ECHO) $(GREEN) "********************************" $(DEFAULT) && \
					$(ECH)

%.o : %.c
					@$(GCC) -c -o $@ $< && \
					$(ECHO) $(GREEN) "[OK] : " $(PURPLE) $(BOLD) $< $(DEFAULT) || \
					$(ECHO) $(BOLD) $(RED) $(ERROR) "[KO] : " $(DEFAULT) $(YELLOW) $< $(DEFAULT)

clean:
					@rm -rf $(COMPIL)

fclean:				clean
					@rm -rf $(NAME) && \
					$(ECHO) $(GREEN) "***********************************" $(DEFAULT) && \
					$(ECHO) $(GREEN) "* SUPPRESSION LIBRAIRIE :TERMINEE *" $(DEFAULT)
					@$(ECHO) $(GREEN) "***********************************" $(DEFAULT)
					@$(ECH)

re:					@fclean $(NAME)

.PHONY : all fclean clean re
