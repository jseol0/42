/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:27:05 by elim              #+#    #+#             */
/*   Updated: 2022/01/22 03:09:11 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_redir(t_redir redir)
{
	int	i;

	free(redir.redir_flag);
	redir.redir_flag = NULL;
	i = 0;
	while (i < redir.redir_cnt)
	{
		free(redir.redir[i]);
		free(redir.filename[i]);
		redir.redir[i] = NULL;
		redir.filename[i] = NULL;
		i++;
	}
	free(redir.redir);
	free(redir.filename);
	redir.redir = NULL;
	redir.filename = NULL;
	return ;
}

static void	ft_free_cmdargs(char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		cmd_args[i] = NULL;
		i++;
	}
	free(cmd_args);
	return ;
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		if (cmd->token)
			ft_free_token(cmd->token, ft_tokensize(cmd->token));
		if (cmd->cmd_args)
			ft_free_cmdargs(cmd->cmd_args);
		if (cmd->redir.redir_cnt)
			ft_free_redir(cmd->redir);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}
