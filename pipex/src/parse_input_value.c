/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:12:06 by jseol             #+#    #+#             */
/*   Updated: 2021/12/22 15:40:21 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_slash(t_cmd *cmd, const char *tmp)
{
	if (ft_strncmp(tmp, "/", 1) == 0
		|| ft_strncmp(tmp, "./", 2) == 0 || ft_strncmp(tmp, "../", 3) == 0)
		cmd->slash = TRUE;
	else
		cmd->slash = FALSE;
}

static char	*find_path(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ret = ft_strdup(envp[i] + 5);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void	parse_input_value(t_pipe *pipe_x, char **argv, char **envp)
{
	char	*pipe_path;

	pipe_x->infile = ft_strdup(argv[1]);
	pipe_x->cmd[0].cmd = ft_split(argv[2], ' ');
	check_slash(&pipe_x->cmd[0], argv[2]);
	pipe_x->cmd[1].cmd = ft_split(argv[3], ' ');
	check_slash(&pipe_x->cmd[1], argv[3]);
	pipe_x->outfile = ft_strdup(argv[4]);
	pipe_path = find_path(envp);
	pipe_x->path = ft_split(pipe_path, ':');
	free(pipe_path);
}
