/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:39:06 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 16:51:10 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	left_redirect(t_cmd *cmd, int redir_idx)
{
	int		fd;
	char	*filename;

	filename = cmd->token[redir_idx + 1].cmd;
	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
	{
		cmd->err.code = ERR_NO_SUCH_FILE;
		if (cmd->err.err_token)
			free(cmd->err.err_token);
		cmd->err.err_token = filename;
		return (ERROR);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	left_redirect_double(t_cmd *cmd, int redir_idx, int pipe_fd[])
{
	char	*line;
	char	*filename;
	int		filelen;

	filename = cmd->token[redir_idx + 1].cmd;
	filelen = ft_strlen(cmd->token[redir_idx + 1].cmd);
	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, filename, filelen) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	pipe(pipe_fd);
	return (0);
}

static int	rigth_redirect(t_cmd *cmd, int redir_idx)
{
	int		fd;
	char	*filename;

	filename = cmd->token[redir_idx + 1].cmd;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd == -1)
		return (ERROR);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	rigth_redirect_double(t_cmd *cmd, int redir_idx)
{
	int		fd;
	char	*filename;

	filename = cmd->token[redir_idx + 1].cmd;
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd == -1)
		return (ERROR);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect(t_cmd *cmd, int pipe_fd[])
{
	int	i;
	int	ret;

	i = 0;
	while (cmd->token[i].cmd)
	{
		if (cmd->token[i].redir_flag != 0 && cmd->token[i].redir_flag != 5)
		{
			ret = file_check(cmd, cmd->redir);
			if (!ret)
				return (ERROR);
			if (cmd->token[i].redir_flag == REDIR_L)
				ret = (left_redirect(cmd, i));
			else if (cmd->token[i].redir_flag == REDIR_LL)
				ret = (left_redirect_double(cmd, i, pipe_fd));
			else if (cmd->token[i].redir_flag == REDIR_R)
				ret = (rigth_redirect(cmd, i));
			else if (cmd->token[i].redir_flag == REDIR_RR)
				ret = (rigth_redirect_double(cmd, i));
			else if (cmd->token[i].redir_flag == REDIR_SYNTAX_ERR)
				ret = err_redirect(cmd, i);
		}
		i++;
	}
	return (ret);
}
