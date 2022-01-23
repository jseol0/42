/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:15:18 by elim              #+#    #+#             */
/*   Updated: 2022/01/20 00:54:17 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_flag(t_flag *flag, int *i, size_t *size)
{
	flag->flag = 0;
	flag->in_quote = 0;
	*i = 0;
	*size = 0;
	return ;
}

static void	flag_up(char c, t_flag *flag, size_t *size)
{
	if (c != ' ')
	{
		flag->flag = 1;
		(*size)++;
	}
	return ;
}

static size_t	get_arg_size(char *line)
{
	size_t	size;
	t_flag	flag;
	int		i;

	init_flag(&flag, &i, &size);
	if (line[i] == '<' || line[i] == '>')
		return (case_redir(&line[i]));
	while (line[i])
	{
		if (line[i] == D_QUOTE || line[i] == S_QUOTE)
			handle_quote_flag(&flag, line[i]);
		if (!flag.flag)
			flag_up(line[i], &flag, &size);
		else
		{
			if (line[i] == ' ' && !flag.in_quote)
				break ;
			if ((line[i] == '<' || line[i] == '>') && !flag.in_quote)
				break ;
			size++;
		}
		i++;
	}
	return (size);
}

static char	*malloc_token_cmd(char *line, int *idx)
{
	char	*ret;
	size_t	size;
	size_t	i;

	size = get_arg_size(&line[*idx]);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = line[*idx + i];
		i++;
	}
	ret[i] = 0;
	*idx += size;
	return (ret);
}

t_token	*malloc_token(char *line, size_t size)
{
	t_token	*ret;
	int		line_idx;
	int		ret_idx;

	ret = (t_token *)malloc(sizeof(t_token) * (size + 1));
	if (!ret)
		return (NULL);
	line_idx = 0;
	ret_idx = 0;
	while (line[line_idx])
	{
		if (line[line_idx] == ' ')
			line_idx++;
		else
		{
			ret[ret_idx].cmd = malloc_token_cmd(line, &line_idx);
			if (!ret[ret_idx].cmd)
				return (ft_free_token(ret, ret_idx));
			ret[ret_idx].redir_flag = 0;
			ret_idx++;
		}
	}
	ret[ret_idx].cmd = NULL;
	return (ret);
}
