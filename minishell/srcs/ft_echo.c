/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:39:19 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/21 01:11:55 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_noption(char *cmd)
{
	int	i;

	i = 1;
	if (ft_strncmp("-n", cmd, 2) != 0)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_cmd *cmd, int fd)
{
	int	i;
	int	flag;
	int	cnt;

	i = 1;
	flag = 0;
	cnt = 0;
	while (cmd->token[i].cmd && is_noption(cmd->token[i].cmd))
	{
		flag = 1;
		i++;
	}
	while (cmd->token[i].cmd && cmd->token[i].redir_flag == 0)
	{
		if (cnt != 0)
			write(fd, " ", 1);
		ft_putstr_fd(cmd->token[i].cmd, fd);
		i++;
		cnt++;
	}
	if (flag == 0)
		write(fd, "\n", 1);
	return (0);
}
