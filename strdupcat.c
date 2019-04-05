/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** strdupcat
*/

#include "my.h"

char	*my_strdup(char const *src)
{
	int i = 0;
	char *dest;

	for (;src[i]; i++);
	dest = malloc(sizeof(char) * (i + 1));
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
