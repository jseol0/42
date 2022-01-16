/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:53:01 by elim              #+#    #+#             */
/*   Updated: 2022/01/11 18:13:02 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_flag(t_flag *flag, int *i, int *cnt)
{
	flag->in_quote = 0;
	flag->redir = 0;
	flag->flag = 0;
	*i = 0;
	*cnt = 0;
	return ;
}

static void	handle_flag_down(t_flag *flag, char c)
{
	if (c != ' ')
		flag->flag = 1;
	if (c == '<' || c == '>')
		flag->redir++;
	return ;
}

size_t	get_split_size(char *line)
{
	t_flag	flag;
	int		i;
	int		cnt;

	init_flag(&flag, &i, &cnt);
	while (line[i])
	{
		if (line[i] == D_QUOTE || line[i] == S_QUOTE)
			handle_quote_flag(&flag, line[i]);
		if (!flag.flag)
			handle_flag_down(&flag, line[i]);
		else
			handle_flag_up(&flag, line, i, &cnt);
		i++;
	}
	if (flag.flag)
		cnt++;
	return (cnt);
}
