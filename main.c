/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** main
*/
#include "my.h"

int	main(int ac, char **av, char **env)
{
	char *b;
	char **n_env;
	char **tab = NULL;
	int i;

	n_env = tab_cpy(env);
	while (42) {
		disprompt();
		for (b = epurstr(get_next_line(0)); b == NULL;)
			my_exit(NULL);
		if (check_semi(b) == -1)
			tab = my_str_to_wordtab(b, ';');
		for (i = 0; tab && tab[i]; i++)
			n_env = check(tab[i], n_env);
		i == 0 ? n_env = check(b, n_env) : 0;
		if (tab)
			freetab(tab);
		tab = NULL;
	}
	return (1);
}

char	**check(char *tmp, char **env)
{
	char **in;
	char **path;
	char i;

	if (check_redir(tmp) == -1 || check_pipe(tmp) == -1)
		return (env);
	else if (check_pipe(tmp) == 1) {
		in = my_str_to_wordtab(tmp, '|');
		env = my_pipe(in, env);
	}
	else {
		in = my_str_to_wordtab(tmp, ' ');
		path = add_path(in, get_path(env));
		i = b_c(in, path);
		env = funch(i, in, path, env);
	}
	return (env);
}

char	**add_path(char **in, char **path)
{
	char **new;
	int i = 0;
	int j = 0;

	while (path && path[i] != NULL)
		i += 1;
	new = malloc((i + 2) * sizeof(char *));
	while (path && path[j] != NULL) {
		new[j] = my_strdup(my_strcat(path[j], my_strcat("/", in[0])));
		j += 1;
	}
	new[j] = my_strdup(in[0]);
	new[j + 1] = NULL;
	return (new);
}

char	**get_path(char **env)
{
	int i = 0;
	char **tab = NULL;

	for (i = 0; env[i]; i++) {
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
		&& env[i][3] == 'H') {
			tab = my_str_to_wordtab(env[i] + 5, ':');
			break;
		}
	}
	if (!env[i])
		return (NULL);
	return (tab);
}

void	print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++) {
		my_putstr(env[i]);
		my_putchar('\n');
	}
}
