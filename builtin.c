/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:51:43 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 20:52:13 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}

int		env_cmnd(void)
{
	int i;

	i = 0;
	while (g_env[i])
	{
		if (!(checkenv(g_env[i])))
			return (1);
		i++;
	}
	print_env(g_env);
	return (1);
}

int		exit_cmnd(void)
{
	clean_env(g_env);
	return (0);
}

int		check_builtin(char *cmnd)
{
	if (ft_strcmp(cmnd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmnd, "env") == 0)
		return (1);
	if (ft_strcmp(cmnd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmnd, "setenv") == 0)
		return (1);
	if (ft_strcmp(cmnd, "unsetenv") == 0)
		return (1);
	if (ft_strcmp(cmnd, "exit") == 0)
		return (1);
	return (0);
}

int		builtin(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (cd_cmnd(args, str_quantity(args)));
	if (ft_strcmp(args[0], "env") == 0)
		return (env_cmnd());
	if (ft_strcmp(args[0], "setenv") == 0)
		return (setenv_cmnd(args[1], args[2]));
	if (ft_strcmp(args[0], "unsetenv") == 0)
		return (unsetenv_cmnd(args[1]));
	if (ft_strcmp(args[0], "echo") == 0)
		return (echo_cmnd(args));
	if (ft_strcmp(args[0], "exit") == 0)
		return (exit_cmnd());
	return (1);
}
