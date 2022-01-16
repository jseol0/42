/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_size_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:54:01 by elim              #+#    #+#             */
/*   Updated: 2022/01/10 03:50:33 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	case_space_out_quote(t_flag *flag, int *cnt)
{
	if (flag->redir)
		flag->redir = 0;
	flag->flag = 0;
	(*cnt)++;
	return ;
}

static void	case_redir_out_qoute(t_flag *flag, char *line, int i, int *cnt)
{
	if (!flag->redir && line[i - 1] != ' ')
		(*cnt)++;
	flag->redir++;
	return ;
}

static void	handle_cnt_redir(t_flag *flag, int *cnt)
{
	if (flag->redir)
		flag->redir = 0;
	(*cnt)++;
	return ;
}

void	handle_flag_up(t_flag *flag, char *line, int i, int *cnt)
{
	char	c;

	c = line[i];
	if (c == ' ' && !flag->in_quote)
		case_space_out_quote(flag, cnt);
	else if ((c == '<' || c == '>') && !flag->in_quote)
		case_redir_out_quote(flag, line, i, cnt);
	else if (line[i - 1] == '<' || line[i - 1] == '>')
	{
		if (c != ' ' && c != S_QUOTE && !flag->in_quote
			&& !(c != '<' || c != '>'))
			handle_cnt_redir(flag, cnt);
		else if ((c == S_QUOTE && flag->in_quote == S_QUOTE)
			|| (c == D_QUOTE && flag->in_quote == D_QUOTE))
			handle_cnt_redir(flag, cnt);
	}
	return ;
}
