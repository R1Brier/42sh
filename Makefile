##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make
##

SRC	=	main.c	\
		exec.c	\
		my_str_to_wordtab.c	\
		check.c		\
		strdupcat.c	\
		cd.c	\
		exit.c	\
		epurstr.c	\
		setenv.c	\
		my_str_isalpha.c	\
		basic_fonc.c	\
		pipe.c	\
		redir.c	\
		get_next_line.c

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re:	fclean all
