/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:48:19 by elim              #+#    #+#             */
/*   Updated: 2022/01/20 00:52:50 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*split_line(char *line, char **env_dup)
{
	t_cmd	*new;
	int		i;
	size_t	size;

	i = 0;
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	size = get_split_size(line);
	new->token = malloc_token(line, size);
	new->token = parse_cmd(new->token, env_dup);
	new->redir = get_redir_struct(new->token);
	new->cmd_args = get_cmd_args(new->token);
	return (new);
}

t_cmd	*ft_cmdnew(char *line, char **env_dup, int exit_flag, int pipe_flag)
{
	t_cmd	*new;

	if (!line)
		return (NULL);
	new = split_line(line, env_dup);
	new->pipe_flag = pipe_flag;
	if (!exit_flag && !pipe_flag)
		new->exit_flag = 1;
	else
		new->exit_flag = 0;
	new->err.code = 0;
	new->err.err_idx = 0;
	new->err.err_token = NULL;
	new->next = NULL;
	return (new);
}
