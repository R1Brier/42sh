/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/
#ifndef _MY_H_
#define _MY_H_
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"

char	**my_unsetenv(char **in, char **env);
char	**my_setenv(char **in, char **env);
char	*concat_new(char **in);
char	**get_path(char **env);
char	**add_path(char **in, char **path);
char	*good_path(char **path, char **in);
int	launch(char *path, char **in, char **env);
void	disprompt(void);
void	my_putstr(char *str);
void	print_env(char **env);
char	**check(char *tmp, char **env);
void	my_putchar(char c);
int	my_strlen(char const *str);
char	*my_strcat(char *str1, char *str2);
int	my_strncmp(char const *a, char const *b, int l);
char	**my_str_to_wordtab(char *str, char c);
char	*my_strdup(char const *src);
void	check_err(pid_t pid);
void	print_nocommand(char *name);
char	**funch(char i, char **in, char **path, char **env);
void	my_cd(char **in, char **env);
void	switch_tohomedir(char **env);
char	b_c(char **in, char **path);
char	*old_dir(char **in, char **env);
char	*cd_basic(char **in, char **env, char *old);
void	set_err(char **in);
void	freetab(char **tab);
void	my_exit(char **in);
int	my_get_nbr(char *str);
int	tablen(char **tab);
char	**tab_cpy(char **tab);
int	unserror(char **in, char **env);
char	*epurstr(char *str);
int	is_alpha(char c);
int	my_str_isalpha(char const *str);
int	check_set(char **in, char **env);
int	check_semi(char *str);
int	check_mall(char *str, int i, int j);
char	**my_redir_out(char **in, char **env, char **path);
int	grd(char **in, char a);
int	is_redir(char **in);
void	path_err(char *path);
int	check_pipe(char *in);
char ***init(char **in);
char	***init_d(char ***t, char **in, char **env);
char	**my_pipe(char **in, char **env);
void	free_three(char ***a, char ***b);
int	check_redir(char *tmp);
int	check_sec(char *tmp);

#endif
