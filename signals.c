/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:34:29 by bellyn-t          #+#    #+#             */
/*   Updated: 2019/09/07 21:34:32 by bellyn-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_sig_code(int sig_code)
{
	if (sig_code == SIGINT)
		return (": Interrupt\n");
	return (NULL);
}

void	print_signal(char *reason, int sig_code)
{
	ft_putstr_fd(reason, STDIN_FILENO);
	ft_putstr(check_sig_code(sig_code));
}

void	handler_interrupt(int signal)
{
	if (signal == SIGINT)
		siglongjmp(g_sig, 1);
}

void	signals(void)
{
	signal(SIGINT, handler_interrupt);
}
