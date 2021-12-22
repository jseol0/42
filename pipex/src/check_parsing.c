/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:13:03 by jseol             #+#    #+#             */
/*   Updated: 2021/12/22 15:43:06 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	set_cmd(t_pipe *pipe_x, t_cmd *cmd)
{
	int		i;
	char	*tmp_path;
	char	*path_cmd;

	i = 0;
	while (pipe_x->path[i])
	{
		tmp_path = ft_strjoin(pipe_x->path[i], "/");
		path_cmd = ft_strjoin(tmp_path, cmd->cmd[0]);
		if (access(path_cmd, F_OK) == 0)
		{
			cmd->path = ft_strdup(path_cmd);
			free(tmp_path);
			free(path_cmd);
			return (TRUE);
		}
		free(tmp_path);
		free(path_cmd);
		i++;
	}
	return (FALSE);
}

static void	check_command(t_pipe *pipe_x)
{
	int	i;

	pipe_x->cmd->error = -1;
	i = 0;
	while (i < 2)
	{
		if (pipe_x->cmd[i].slash == FALSE)
		{
			if (set_cmd(pipe_x, &pipe_x->cmd[i]) == FALSE)
			{
				pipe_x->cmd->error = i;
				if (pipe_x->cmd->error == 0)
					perror("command not found");
				else
				{
					ft_free(pipe_x);
					ft_error("command not found");
				}
			}
		}
		else
			pipe_x->cmd[i].path = ft_strdup(pipe_x->cmd[i].cmd[0]);
		i++;
	}
}

void	check_parsing(t_pipe *pipe_x)
{
	if (pipe_x->path == NULL && (pipe_x->cmd[0].slash == FALSE
			|| pipe_x->cmd[1].slash == FALSE))
	{
		ft_free(pipe_x);
		ft_error("Wrong path");
	}
	check_command(pipe_x);
}
