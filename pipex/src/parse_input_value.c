/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:12:06 by jseol             #+#    #+#             */
/*   Updated: 2021/11/23 14:50:39 by jseol            ###   ########.fr       */
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

void	parse_input_value(t_tmp *tmp, char **argv, char **envp)
{
	char	*tmp_path;

	tmp->infile = ft_strdup(argv[1]);
	tmp->cmd[0].cmd = ft_split(argv[2], ' ');
	check_slash(&tmp->cmd[0], argv[2]);
	tmp->cmd[1].cmd = ft_split(argv[3], ' ');
	check_slash(&tmp->cmd[1], argv[3]);
	tmp->outfile = ft_strdup(argv[4]);
	tmp_path = find_path(envp);
	tmp->path = ft_split(tmp_path, ':');
	free(tmp_path);
}
