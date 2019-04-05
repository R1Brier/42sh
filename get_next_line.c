/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line
*/

#include "my.h"

char	*my_strcat(char *str1, char *str2)
{
	char	*str;
	int	len;
	int	i = -1;
	int	j = -1;

	len = my_strlen(str1) + my_strlen(str2) + 1;
	if ((str = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	while (str1 && str1[++i] != '\0')
		str[i] = str1[i];
	i--;
	while (str2 && str2[++j] != '\0')
		str[++i] = str2[j];
	str[++i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *buffer;
	int size = 0;
	int n;

	if (str == NULL){
		if ((str = malloc(sizeof(char))) == NULL)
			return (NULL);
		str[0] = 0;
	}
	if ((buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL
	|| (size = read(fd, buffer, READ_SIZE)) == -1)
		return (NULL);
	if (size == 0)
		return (NULL);
	buffer[size] = 0;
	str = my_strcat(str, buffer);
	for (size = 0; str[size] && str[size] != '\n'; size++);
	if (str[size] == 0)
		return (get_next_line(fd));
	if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	buffer[size] = 0;
	for (n = 0; n < size; n++)
		buffer[n] = str[n];
	str += size + 1;
	return (buffer);
}
