/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cd.c
*/
#include "my.h"

void	my_cd(char **in, char **env)
{
	static char *o = NULL;
	static char *old2 = NULL;
	char dir[1024];

	if (!in[1]) {
		o = getcwd(dir, sizeof(dir));
		switch_tohomedir(env);
	}
	else if (in[1] && !in[2]) {
		if (in[1][0] == '-' && in[1][1] == 0) {
			o ? old2 = my_strdup(o) : 0;
			o ? o = getcwd(dir, sizeof(dir)) : 0;
			o ? chdir(old2) : 0;
			!o ? write(2, ": No such file or directory.\n", 29) : 0;
		}
		else
			o = cd_basic(in, env, o);
	}
	else
		write(2, "cd: Too much arguments.\n", 24);
}

char	*cd_basic(char **in, char **env, char *old)
{
	struct stat st;
	char dir[1024];
	char *new;

	if (stat(in[1], &st) == 0 && !in[2]) {
		if (!S_ISDIR(st.st_mode)) {
			write(2, in[1], my_strlen(in[1]));
			write(2, ": Not a directory.\n", 19);
		}
	}
	else if (stat(in[1], &st) != 0)
		set_err(in);
	new = getcwd(dir, sizeof(dir));
	return ((chdir(in[1]) == - 1) ? old : new);
}

void	set_err(char **in)
{
	if (errno == EACCES) {
		write(2, in[1], my_strlen(in[1]));
		write(2, ": Permission denied.\n", 21);
	}
	else if (errno == ENOENT) {
		write(2, in[1], my_strlen(in[1]));
		write(2, ": No such file or directory.\n", 29);
	}
}

void	switch_tohomedir(char **env)
{
	char *home;
	int i = 0;

	while (env[i] != NULL) {
		if (my_strncmp(env[i], "HOME=", 5) == 1)
			home = my_strdup(env[i] + 5);
		i++;
	}
	chdir(home);
}
