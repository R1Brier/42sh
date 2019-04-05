/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** exit
*/
#include "my.h"

void	my_exit(char **in)
{
	int i = 0;

	if (in == NULL) {
		write(1, "exit\n", 5);
		exit(i);
	}
	if (in[1]) {
		for (i = my_get_nbr(in[1]); i == -1 || in[2];) {
			write(2, "exit: Invalid Syntax.\n", 22);
			return;
		}
	}
	write(1, "exit\n", 5);
	exit(i);
}

int	my_get_nbr(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i] >= 48 && str[i] <= 57) {
		n = n + (str[i] - 48);
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			n *= 10;
		i++;
	}
	if (str[i] == '\0' || str[i] == '\n')
		return (n);
	else
		return (-1);
}

char	**tab_cpy(char **tab)
{
	int i;
	char **n_tab;

	for (n_tab = malloc((tablen(tab) + 1) * sizeof(char *)); n_tab == NULL;)
		return (NULL);
	for (i = 0; tab[i]; i++)
		n_tab[i] = my_strdup(tab[i]);
	n_tab[i] = NULL;
	return (n_tab);
}

int	tablen(char **tab)
{
	int i;

	for (i = 0; tab[i]; i++);
	return (i);
}
