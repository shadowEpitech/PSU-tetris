##
## Makefile for  in /home/shadow/tetris
## 
## Made by nicolas djurovic
## Login   <shadow@epitech.net>
## 
## Started on  Sun Mar 19 14:06:19 2017 nicolas djurovic
## Last update Sun Mar 19 14:25:29 2017 nicolas djurovic
##

SRC_PRE=		src/

SRC_FILES=		main.c			\
			clean.c		\
			get_next_line.c		\
			load.c			\
			add_tetri.c		\
			score.c			\
			board.c			\
			my_memset.c		\
			init_game.c		\
			display.c		\
			my_getnbr.c		\
			my_strlen.c		\
			copy_tetri.c		\
			my_strncmp.c		\
			my_strcmp.c		\
			my_strndup.c		\
			my_str_to_wordtab.c	\
			random.c		\
			interface.c		\
			check_file.c		\
			check_args.c		\
			add_name.c		\
			get_t.c		\
			select.c		\
			errors.c		\
			free.c			\
			debug.c			\
			my_put_nbr.c		\
			check_end.c		\
			check_line.c		\
			order.c			\
			pause.c			\
			args/debug.c		\
			args/help.c		\
			args/keysLR.c		\
			args/keysQP.c		\
			args/keysTD.c		\
			args/level.c		\
			args/next.c		\
			args/size.c		\
			events/game.c		\
			events/move.c

SRC=			$(addprefix $(SRC_PRE),$(SRC_FILES))

NAME=			tetris

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

LIB=			-lncurses

OBJ=			$(SRC:.c=.o)

$(NAME):	$(OBJ)

ifeq ($(DEBUG), yes)

endif
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled game"
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
