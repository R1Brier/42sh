/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** redir.c
*/
#include "my.h"

int	check_redir(char *tmp)
{
	if (tmp[my_strlen(tmp) - 1] == '<'
	|| tmp[my_strlen(tmp) - 1] == '>') {
		write(2, "Missing name for redirect.\n", 27);
		return (-1);
	}
	else if (tmp[0] == '>' || tmp[0] == '<') {
		write(2, "Invalid null command.\n", 22);
		return (-1);
	}
	else
		return (1);
}

