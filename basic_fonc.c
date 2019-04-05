/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** basic_fonc
*/

#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int m = 0;

	while (str[m] != '\0') {
		my_putchar(str[m]);
		m = m + 1;
	}
}

int	my_strlen(char const *str)
{
	int i;

	for (i = 0; str[i]; i++);
	return (i);
}
