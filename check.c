/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** check
*/

#include "my.h"

int	my_strncmp(char const *a, char const *b, int z)
{
	int i = 0;

	while (a[i] && b[i] && i != z && a[i] == b[i])
		i++;
	if (i == z)
		return (1);
	else
		return (0);
}

int	my_strcmp(char const *a, char const *b)
{
	int i;

	for (i = 0; a[i] && b[i] && a[i] == b[i]; i++);
	if (!a[i] && !b[i])
		return (1);
	else
		return (0);
}

char	b_c(char **in, char **path)
{
	if (my_strcmp(in[0], "cd") == 1)
		return (1);
	if (my_strcmp(in[0], "env") == 1)
		return (2);
	if (my_strcmp(in[0], "setenv") == 1)
		return (3);
	if (my_strcmp(in[0], "unsetenv") == 1)
		return (4);
	if (my_strcmp(in[0], "exit") == 1)
		return (5);
	if (good_path(path, in) != NULL && my_strcmp(in[0], "bin/ls") != 1)
		return (6);
	return (7);
}

char	**funch(char i, char **in, char **path, char **env)
{
	i == 1 ? my_cd(in, env) : 0;
	i == 2 ? print_env(env) : 0;
	i == 3 ? env = my_setenv(in, env) : 0;
	i == 4 ? env = my_unsetenv(in, env) : 0;
	i == 5 ? my_exit(in) : 0;
	i == 6 ? launch(good_path(path, in), in, env) : 0;
	i == 7 ? print_nocommand(in[0]) : 0;
	return (env);
}

void	freetab(char **tab)
{
	int i;

	for (i = 0; tab[i]; ++i)
		free(tab[i]);
	free(tab);
}
