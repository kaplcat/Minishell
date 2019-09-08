/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolutepath_launch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:10:26 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 21:10:28 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch(char *file, char **args, int absolute)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(file, args, g_env) == -1)
			perror_cmnd("minishell", NULL, EXECVEERR);
		if (!absolute)
			free(file);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror_cmnd("minishell", NULL, FORKERR);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	if (!absolute)
		free(file);
	return (1);
}

int		absolute_path_launch(char **cmnd)
{
	if (access(cmnd[0], X_OK))
	{
		if (access(cmnd[0], F_OK) == -1)
			perror_cmnd("minishell", cmnd[0], CMNDNTFND);
		else
			perror_cmnd("minishell", cmnd[0], PMDND);
		return (1);
	}
	return (launch(cmnd[0], cmnd, 1));
}
