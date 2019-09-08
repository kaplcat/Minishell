/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:17:24 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 21:17:41 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_env_cp(char **env_dst, char **env_origin)
{
	int i_origin;
	int j_dst;

	i_origin = 0;
	j_dst = 0;
	while (env_origin[i_origin])
		i_origin++;
	if (!(env_dst = (char **)malloc(sizeof(char *) * (i_origin + 1))))
		perror_cmnd("minishell", NULL, MLKERR);
	while (j_dst < i_origin)
	{
		env_dst[j_dst] = ft_strdup(env_origin[j_dst]);
		j_dst++;
	}
	env_dst[j_dst] = NULL;
	return (env_dst);
}

void	print_usage(void)
{
	ft_putstr("usage: minishell\n");
}

int		main(int argc, char **argv, char **env)
{
	argv = NULL;
	if (argc == 1)
	{
		g_env = make_env_cp(g_env, env);
		cmnd_loop();
	}
	else
		print_usage();
	return (0);
}
