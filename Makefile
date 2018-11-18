##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	my_hunter

SRCPATH	=	src/

LIBPATH	=	lib/

SRC	=	$(SRCPATH)main.c				\
		$(SRCPATH)master.c				\
		$(SRCPATH)kill_duck.c			\
		$(SRCPATH)game_over.c			\
		$(SRCPATH)duck.c				\
		$(SRCPATH)error_management.c	\
		$(SRCPATH)master_load.c			\
		$(LIBPATH)my_strcmp.c			\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc 

CFLAGS	=	-Wall -Wextra -ofast

CPPFLAGS=	-Iinclude

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

lclean: fclean
	make -Clibs fclean
re: fclean all

.PHONY: all clean fclean re
