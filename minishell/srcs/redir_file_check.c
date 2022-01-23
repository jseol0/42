/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:54:51 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 06:09:56 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_redirect(t_cmd *cmd, int i)
{
	cmd->err.code = ERR_REDIR_SNTAX;
	cmd->err.err_token = cmd->token[i].cmd;
	return (ERROR);
}

static int	set_err_struct(t_cmd *cmd, int flag)
{
	cmd->err.code = ERR_REDIR_SNTAX;
	if (flag == 0)
		cmd->err.err_token = STR_NL;
	else if (flag == 1)
		cmd->err.err_token = STR_LL;
	else if (flag == 2)
		cmd->err.err_token = STR_RR;
	else if (flag == 3)
		cmd->err.err_token = STR_L;
	else
		cmd->err.err_token = STR_R;
	return (0);
}

int	file_check(t_cmd *cmd, t_redir redir)
{
	int	i;

	i = 0;
	if (!redir.filename[0])
		return (set_err_struct(cmd, 0));
	while (redir.filename[i])
	{
		if ((ft_strncmp("<<", redir.filename[i], 2)) == 0)
			return (set_err_struct(cmd, 1));
		else if ((ft_strncmp(">>", redir.filename[i], 2)) == 0)
			return (set_err_struct(cmd, 2));
		else if ((ft_strncmp("<", redir.filename[i], 1)) == 0)
			return (set_err_struct(cmd, 3));
		else if ((ft_strncmp(">", redir.filename[i], 1)) == 0)
			return (set_err_struct(cmd, 4));
		i++;
	}
	return (1);
}
