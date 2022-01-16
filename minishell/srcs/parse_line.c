/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:03:43 by elim              #+#    #+#             */
/*   Updated: 2022/01/11 19:33:15 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_flag(t_cmd **head, t_flag *flag, int *i, int *start)
{
	*head = NULL;
	flag->pipe = 1;
	flag->in_quote = 0;
	*i = 0;
	*start = 0;
	return ;
}

void	handle_quote_flag(t_flag *flag, int c)
{
	if (!flag->in_quote)
	{
		if (c == D_QUOTE)
			flag->in_quote = D_QUOTE;
		else if (c == S_QUOTE)
			flag->in_quote = S_QUOTE;
	}
	else
	{
		if (c == D_QUOTE && flag->in_quote == D_QUOTE)
			flag->in_quote = 0;
		else if (c == S_QUOTE && flag->in_quote == S_QUOTE)
			flag->in_quote = 0;
	}
	return ;
}

static void	handle_pipe_null(char *c, int *pipe_flag)
{
	if (*c == PIPE)
		*c = 0;
	else
		*pipe_flag = 0;
	return ;
}

t_cmd	*parse_line(char **env_dup, char *line)
{
	t_cmd	*head;
	t_cmd	*new;
	t_flag	flag;
	int		i;
	int		start;

	init_flag(&head, &flag, &i, &start);
	while (1)
	{
		if (line[i] == D_QUOTE || line[i] == S_QUOTE)
			handle_quote_flag(&flag, line[i]);
		if (line[i] == 0 || (line[i] == PIPE && !flag.in_quote))
		{
			handle_pipe_null(&line[i], &flag.pipe);
			new = ft_cmdnew(line + start, env_dup, start, flag.pipe);
			if (!new)
				return (NULL); // handle error
			ft_cmdadd_back(&head, new);
			if (!flag.pipe)
				break ;
			start = i + 1;
		}
		i++;
	}
	return (head);
}
