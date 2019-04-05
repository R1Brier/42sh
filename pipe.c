/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** pipe
*/
#include "my.h"

char	**my_pipe(char **in, char **env)
{
	int fd[4];
	int i;
	char ***t;
	char ***p;

	t = init(in);
	p = init_d(t, in, env);
	for (i = 0; t[i]; i++) {
		fd[2] = dup(0);
		fd[3] = dup(1);
		fd[1] = open(((i % 2 == 0) ? "./.y" : "./.x"),
		O_WRONLY | O_TRUNC);
		fd[0] = open(((i % 2 == 0) ? "./.x" : "./.y"), O_RDONLY);
		(t[i + 1]) ? dup2(fd[1], 1) : 0;
		i > 0 ? dup2(fd[0], 0) : 0;
		env = funch(b_c(t[i], p[i]), t[i], p[i], env);
		dup2(fd[2], 0);
		dup2(fd[3], 1);
	}
	free_three(t, p);
	return (env);
}

void	free_three(char ***a, char ***b)
{
	int i;
	int j;

	for (i = 0; a[i]; i++) {
		for (j = 0; a[i][j]; j++)
			free(a[i][j]);
		free(a[i]);
	}
	free(a);
	for (i = 0; b[i]; i++) {
		for (j = 0; b[i][j]; j++)
			free(b[i][j]);
		free(b[i]);
	}
	free(b);
}

char	***init(char **in)
{
	int i;
	char ***t;

	for (t = malloc((tablen(in) + 8) * sizeof(char **));
	t == NULL;)
		return (NULL);
	for (i = 0; in[i]; i++)
		t[i] = my_str_to_wordtab(in[i], ' ');
	t[i] = NULL;
	return (t);
}

char	***init_d(char	***t, char **in, char **env)
{
	int i;
	char ***p;

	for (p = malloc((tablen(in) + 1) * sizeof(char **));
	p == NULL;)
		return (NULL);
	for (i = 0; t[i]; i++) {
		p[i] = add_path(t[i], get_path(env));
	}
	p[i] = NULL;
	return (p);
}

int	check_pipe(char *in)
{
	int i;

	if (in[0] == '|' || in[my_strlen(in) - 1] == '|') {
		write(2, "Invalid null command.\n", 22);
		return (-1);
	}
	for (i = 0; in[i]; i++)
		if (in[i] == '|')
			return (1);
	return (0);
}
