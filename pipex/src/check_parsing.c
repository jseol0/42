/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:13:03 by jseol             #+#    #+#             */
/*   Updated: 2021/11/20 17:41:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	set_cmd(t_tmp *tmp, t_cmd *cmd)
{
	int i;
	char	*tmp_path;
	char	*path_cmd;

	i = 0;
	while (tmp->path[i])
	{
		tmp_path = ft_strjoin(tmp->path[i], "/");
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

static void	check_command(t_tmp *tmp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (tmp->cmd[i].slash == FALSE)
		{
			if (set_cmd(tmp, &tmp->cmd[i]) == FALSE)
			{
				// ft_free(tmp);
				ft_error("Command not found");
			}
		}
		else
			tmp->cmd[i].path = ft_strdup(tmp->cmd[i].cmd[0]);
		i++;
	}
}

void	check_parsing(t_tmp *tmp)
{
	tmp->infile_fd = open(tmp->infile, O_RDWR);
	if (tmp->infile_fd < 0)
	{
		// ft_free(tmp);
		close(tmp->infile_fd);
		ft_error("Not valid infile");
	}
	close(tmp->infile_fd);
	tmp->outfile_fd = open(tmp->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp->outfile_fd < 0)
	{
		// ft_free(tmp);
		close(tmp->outfile_fd);
		ft_error("Not valid outfile");
	}
	close(tmp->outfile_fd);
	if (tmp->path == NULL && (tmp->cmd[0].slash == FALSE || tmp->cmd[1].slash == FALSE))
	{
		// ft_free(tmp);
		ft_error("Wrong path");
	}
	check_command(tmp);
}
