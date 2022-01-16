/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 07:39:12 by elim              #+#    #+#             */
/*   Updated: 2022/01/07 17:32:06 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal.h"

static void	ft_sigint(int signo)
{
	pid_t	pid;
	int		status;

	(void)signo;
	pid = waitpid(-1, &status, WNOHANG);
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
	return ;
}

static void	ft_sigquit(int signo)
{
	pid_t	pid;
	int		status;

	(void)signo;
	pid = waitpid(-1, &status, WNOHANG);
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	return ;
}

void	init_sig(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_sigquit);
	return ;
}
