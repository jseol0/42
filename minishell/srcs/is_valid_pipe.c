/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:01:54 by elim              #+#    #+#             */
/*   Updated: 2022/01/24 16:22:56 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_last_pipe(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (!(('\t' <= line[i] && line[i] <= '\r') || line[i] == ' '))
		{
			if (line[i] == '|')
				return (1);
			else
				break ;
		}
		i--;
	}
	return (0);
}

static int	is_1st_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(('\t' <= line[i] && line[i] <= '\r') || line[i] == ' '))
		{
			if (line[i] == '|')
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

int	is_valid_pipe(char *line)
{
	if (is_1st_pipe(line) || is_last_pipe(line))
	{
		write(STDERR_FILENO,
			"minishell: syntax error near unexpected token `|'\n", 50);
		g_exit_status = 258;
		return (0);
	}
	return (1);
}

void	parse_and_exec(t_cmd **cmd, char ***env_dup, char *line)
{
	*cmd = parse_line(*env_dup, line);
	g_exit_status = exec(*cmd, env_dup);
	ft_free_cmd(*cmd);
}
