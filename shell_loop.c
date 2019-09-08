/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:48:14 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/08 13:48:17 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		str_quantity(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	cmnd_loop(void)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		signals();
		rl_attempted_completion_function = cmnd_completion;
		while (sigsetjmp(g_sig, 1) != 0)
			ft_putchar_fd('\n', STDOUT_FILENO);
		if ((line = readline(SHELL_NAME)))
			status = execution(line);
		else
		{
			ft_putchar_fd('\n', STDOUT_FILENO);
			return ;
		}
	}
}
