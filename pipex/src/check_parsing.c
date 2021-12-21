/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:13:03 by jseol             #+#    #+#             */
/*   Updated: 2021/12/21 22:23:52 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	set_cmd(t_tmp *tmp, t_cmd *cmd)
{
	int		i;
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

	tmp->cmd->error = -1;
	i = 0;
	while (i < 2)
	{
		if (tmp->cmd[i].slash == FALSE)
		{
			if (set_cmd(tmp, &tmp->cmd[i]) == FALSE)
			{
				tmp->cmd->error = i;
				if (tmp->cmd->error == 0)
					perror("command not found");
				else
				{
					ft_free(tmp);
					ft_error("command not found");
				}
			}
		}
		else
			tmp->cmd[i].path = ft_strdup(tmp->cmd[i].cmd[0]);
		i++;
	}
}

void	check_parsing(t_tmp *tmp)
{
	if (tmp->path == NULL && (tmp->cmd[0].slash == FALSE
			|| tmp->cmd[1].slash == FALSE))
	{
		ft_free(tmp);
		ft_error("Wrong path");
	}
	check_command(tmp);
}
