/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:14:18 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 21:14:36 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	 execute_cmnd(char **cmnd)
{
	int execute_status;
	char *path;

	execute_status = 1;
	if (cmnd[0] == NULL)
		return (1);
	else if (*cmnd[0] == '/' || *cmnd[0] == '.')
		execute_status = absolute_path_launch(cmnd);
	else if (check_builtin(cmnd[0]) == 1)
		execute_status = builtin(cmnd);
	else if ((path = check_extern_command(cmnd, -1)))
		execute_status = external_launch(cmnd, path);
	else
		perror_cmnd("minishell", cmnd[0], CMNDNTFND);
	return (execute_status);
}

int	 exe_multcmnds(char *line)
{
	int i;
	char **args;
	char **mult_args;
	int status;

	status = 0;
	if (!(args = ft_strsplit(line, ';')))
	    perror_cmnd("minishell", NULL, MLKERR);
	i = -1;
	while (args[++i])
	{
		mult_args = split_cmnd(args[i], ' ');
		status = execute_cmnd(mult_args);
		clean_env(mult_args);
		if (status == 0)
		{
			clean_env(args);
			break;
		}
	}
	clean_env(args);
	return (status);
}

int	 exe_cmnds(char *line)
{
	char **args;
	int status;

	args = split_cmnd(line, ' ');
	status = execute_cmnd(args);
	clean_env(args);
	return (status);
}

int	 execution(char *line)
{
	int status;

	if ((strrchr(line, ';')))
		status = exe_multcmnds(line);
	else
		status = exe_cmnds(line);
	add_history(line);
	free(line);
	return (status);
}
