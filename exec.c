/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** exec
*/
#include "my.h"

char	*good_path(char **path, char **in)
{
	int i;
	char *str = my_strcat("/usr/local/bin/", in[0]);
	char *str2 = my_strcat("/usr/bin/", in[0]);
	char *str3 = my_strcat("/bin/", in[0]);

	for (i = 0; path[i] && access(path[i], F_OK) != 0; i++);
	if (path[i])
		return (path[i]);
	if (access(str, F_OK) == 0)
		return (str);
	if (access(str2, F_OK) == 0)
		return (str2);
	if (access(str2, F_OK) == 0)
		return (str3);
	return (NULL);
}

int	launch(char *path, char **in, char **env)
{
	pid_t pid;

	for (pid = fork(); pid == -1;) {
		perror("fork");
		return (0);
	}
	if (pid == 0) {
		if (execve(path, in, env) == -1)
			path_err(path);
		return (0);
	}
	else
		check_err(pid);
	return (1);
}

void    check_err(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
	if (WTERMSIG(status) == 8) {
		write (2, "Floating exception", 18);
		WCOREDUMP(status) ? write(2, " (core dumped)", 14) : 0;
		write(2, "\n", 1);
	}
	if (WTERMSIG(status) == 11) {
		write(2, "Segmentation fault", 18);
		WCOREDUMP(status) ? write(2, " (core dumped)", 14) : 0;
		write (2, "\n", 1);
	}
}

void	print_nocommand(char *name)
{
	write(2, name, my_strlen(name));
	write(2, ": Command not found.\n", 21);
}

void	disprompt(void)
{
	write(0, "[420~]$ ", 8);
}
