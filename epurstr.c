/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** epurstr
*/
#include "my.h"

char	*epurstr(char *str)
{
	char *new;
	int i;
	int j;

	for (j = check_mall(str, i, j); j == 0;)
		return (NULL);
	for (new = malloc((j + 1) * sizeof(char)); new == NULL;)
		return (NULL);
	for (i = 0, j = 0; str[i]; i++, j++) {
		if ((str[i] == ' ' || str[i] == '\t')
		&& str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '\t')
			new[j] = ' ';
		else
			(str[i] == ' ' || str[i] == '\t') ?
			j -= 1 : (new[j] = str[i]);
	}
	new[j] = '\0';
	return (new);
}

int	check_mall(char *str, int i, int j)
{
	if (!str)
		return (0);
	for (i = 0, j = 0; str[i]; i++, j++)
		if ((str[i] == ' ' || str[i] == '\t')
		&& (!str[i + 1] || str[i + 1]  == ' ' || str[i + 1] == '\t'))
			j--;
	return (j);
}
