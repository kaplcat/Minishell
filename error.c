/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:12:48 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 21:12:51 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_error_code_dope(int error_code)
{
	if (error_code == 9)
		return (": \e[91mmalloc() error\e[39m");
	if (error_code == 10)
		return (": not a directory: ");
	if (error_code == 11)
		return (": \e[91mchdir() error:\e[39m ");
	if (error_code == 12)
		return (": \e[91msetenv() error\e[39m");
	if (error_code == 13)
		return (": no such file or directory: ");
	if (error_code == 14)
		return (": permission denied: ");
	return (NULL);
}

char	*check_error_code(int error_code)
{
	if (error_code == 1)
		return (": string not in pwd: ");
	if (error_code == 2)
		return (": too many arguments");
	if (error_code == 3)
		return (": \e[91mgetcwd() error:\e[39m ");
	if (error_code == 5)
		return (": \e[91mstat() error\e[39m");
	if (error_code == 4)
		return (": \e[91mlstat() error\e[39m");
	if (error_code == 6)
		return (": command not found: ");
	if (error_code == 7)
		return (": \e[91mexecve() error\e[39m");
	if (error_code == 8)
		return (": \e[91mfork() error\e[39m");
	return (check_error_code_dope(error_code));
}

void	perror_cmnd(char *cmnd, char *error_path, int error_code)
{
	ft_putstr_fd(cmnd, STDOUT_FILENO);
	if (error_code != 0)
		ft_putstr(check_error_code(error_code));
	else
		ft_putstr_fd(": ", STDOUT_FILENO);
	if (error_path)
		ft_putstr_fd(error_path, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
