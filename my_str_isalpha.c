/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** str_is_alpha
*/
#include "my.h"

int	my_str_isalpha(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < 123 && str[i] > 96 || str[i] < 91 && str[i] > 64)
			i++;
		else if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	if (str[i] == '\0')
		return (1);
}

int	is_alpha(char c)
{
	if (c < 123 && c > 96 || c < 91 && c > 64)
		return (1);
	else
		return (0);
}

int	check_semi(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] == ';' && str[i + 1] != 0)
			return (-1);
	return (0);
}

void	path_err(char *path)
{
	struct stat st;

	stat(path, &st);
	if (errno == EACCES || S_ISDIR(st.st_mode)) {
		write(2, path, my_strlen(path));
		write(2, ": Permission denied.\n", 21);
	}
	else if (errno == ENOEXEC) {
		write(2, path, my_strlen(path));
		write(2, ": Exec format error. Wrong Architecture.\n", 41);
	}
}
