/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:45:55 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 16:42:12 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_exit(t_cmd *cmd)
{
	long long	ret;

	ret = ft_atoi_exit(cmd->token[1].cmd);
	if (ret == -1)
	{
		cmd->err.code = ERR_NUM_ARG_REQUIRED;
		cmd->err.err_token = cmd->token[1].cmd;
		ft_error(cmd);
		exit(-1);
	}
	else if (ret >= 0)
		exit(ret % 256);
	else if (ret < 0)
		exit(256 + ret);
}

int	ft_exit(t_cmd *cmd)
{
	if (cmd->exit_flag == 1 && cmd->pipe_flag == 0)
		printf("exit\n");
	if (cmd->token[1].cmd != NULL)
	{
		if (check_digit(cmd) == 0)
		{
			cmd->err.code = ERR_NUM_ARG_REQUIRED;
			cmd->err.err_token = cmd->token[1].cmd;
			ft_error(cmd);
			exit(-1);
		}
		if (cmd->token[2].cmd != NULL)
		{
			cmd->err.code = ERR_TOO_MANY_ARGS;
			cmd->err.err_token = cmd->token[0].cmd;
			return (ERROR);
		}
	}
	else if (cmd->exit_flag == 1 && cmd->pipe_flag == 0)
		exit(0);
	if (cmd->exit_flag == 1 && cmd->pipe_flag == 0)
		exec_exit(cmd);
	return (0);
}
