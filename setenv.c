/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** setenv
*/

#include "my.h"

char	**my_setenv(char **in, char **env)
{
	int i;
	int z = -1;
	char **new;

	for (;check_set(in, env) == -1;)
		return (env);
	for (i = 0; env[i]; i++)
		if (my_strncmp(in[1], env[i], my_strlen(in[1])) == 1)
			z = i;
	for (new = malloc((i + ((z != - 1) ? 1 : 2)) * sizeof(char *));
	new == NULL;)
		return (NULL);
	for (i = 0; env[i]; i++)
		new[i] = (i == z) ? concat_new(in) : my_strdup(env[i]);
	new[i] = (z == -1) ? concat_new(in) : NULL;
	(new[i]) ? (new[i + 1] = NULL) : 0;
	return (new);
}

int	check_set(char **in, char **env)
{
	if (!in[1]) {
		print_env(env);
		return (-1);
	}
	if (is_alpha(in[1][0]) == 0) {
		write(2, "setenv: Variable name must begin with a lette", 45);
		write(2, "r.\n", 3);
		return (-1);
	}
	else if (my_str_isalpha(in[1]) == 0) {
		write(2, "setenv: Variable ", 17);
		write(2, "name must contain alphanumeric characters.\n", 43);
		return (-1);
	}
	else
		return (0);
}

char	*concat_new(char **in)
{
	char *a;
	char *b;

	a = my_strcat(in[1], "=");
	if (in[2]) {
		b = my_strcat(a, in[2]);
		return (b);
	}
	else
		return (a);
}

char	**my_unsetenv(char **in, char **env)
{
	int i = 0;
	int t;
	int j = 0;
	char **new;

	for (t = unserror(in, env); t == -1;)
		return (env);
	for (new = malloc(tablen(env) * sizeof(char *));
	new == NULL;)
		return (NULL);
	for (i = 0, j = 0; env[i]; j++, i++) {
		if (i != t)
			new[j] = my_strdup(env[i]);
		else
			j--;
	}
	new[j] = NULL;
	return (new);
}

int	unserror(char **in, char **env)
{
	int i = 0;

	if (!in[1]) {
		write(2, "unsetenv: Not enough arguments.\n", 32);
		return (-1);
	}
	for (i = 0; env[i]; i++)
		if (my_strncmp(in[1], env[i], my_strlen(in[1])) == 1)
			return (i);
	return (-1);
}
