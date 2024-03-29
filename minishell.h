/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:40:47 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/08 16:09:25 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/dir.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <setjmp.h>

# define NOTINPWD 1
# define MNARGS 2
# define GETCWDERR 3
# define LSTATERR 4
# define STATERR 5
# define CMNDNTFND 6
# define EXECVEERR 7
# define FORKERR 8
# define MLKERR 9
# define NOTDIR 10
# define CHDIRERR 11
# define SETENVERR 12
# define NOFLODIR 13
# define PMDND 14

# define MAXDIR 4095

# define SHELL_NAME "\e[95m\e[1mminishell\e[0m🌚  "

char		**g_env;
sigjmp_buf	g_sig;

int		launch(char *file, char **args, int absolute);
int		absolute_path_launch(char **cmnd);
void	print_env(char **env);
int		env_cmnd(void);
int		exit_cmnd(void);
int		check_builtin(char *cmnd);
int		builtin(char **args);
void	launch_cd(char *path);
int		cd_cmnd(char **args, int argc);
int		echo_cmnd(char **args);
char	*check_error_code(int error_code);
char	*check_error_code_dope(int error_code);
void	perror_cmnd(char *cmnd, char *error_path, int error_code);
int		find_bin(char *cmnd_name, char *path);
char	*path(char *name, char *path);
char	*check_extern_command(char **cmnd, int i);
int		external_launch(char **cmnd, char *paths);
void	clean_env(char **env_cp);
void	free_parse(char **parse, int w);
void	free_copy_envp(char ***envp);
int		str_quantity(char **env);
int		check_existenv(const char *name, char *request);
int		get_envindex(const char *name);
int		checkenv(char *envstr);
char	*getenv_cmnd(char *name);
int		execute_cmnd(char **cmnd);
char	**make_env_cp(char **env_dst, char **env_origin);
void	print_usage(void);
int		main(int argc, char **argv, char **env);
void	join_value(char **ress, char *name, char *value);
void	copy_to_realloc(char **envp, char **res, char *name, char *value);
char	**realloc_envp(int pointers, char *name, char *value, char **env);
int		setenv_cmnd(char *name, char *value);
void	cmnd_loop(void);
void	signals(void);
void	handler_interrupt(int signal);
char	*check_sig_code(int sig_code);
char	**split(char **str, char *s, char c, int count);
int		count_words(char *str, char sign);
char	**split_cmnd(char const *s, char c);
void	copy_realloc_del(char **res, char **env, int index);
char	**realloc_envp_del(int p, char *name, char **env);
int		unsetenv_cmnd(char *name);
int		env_strlen(char *s);
char	*cmnd_generator(const char *text, int state);
char	**cmnd_completion(const char *text, int start, int end);
int		getenv_strlen(char *str);
char	*malloc_line(char *name, char *value);
int		execute_cmnd(char **cmnd);
int		exe_multcmnds(char *line);
int		exe_cmnds(char *line);
int		execution(char *line);
void	check_cd(int argc, char **args, int cwderr);

#endif
