/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:36:46 by elim              #+#    #+#             */
/*   Updated: 2022/01/22 02:12:59 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_redir_cnt(t_token *token)
{
	int		ret;
	size_t	i;

	i = 0;
	ret = 0;
	while (token[i].cmd)
	{
		if (token[i].redir_flag)
			ret++;
		i++;
	}
	return (ret);
}

static void	malloc_redir_struct(t_redir *new)
{
	int		i;

	i = 0;
	new->filename = (char **)malloc(sizeof(char *) * (new->redir_cnt + 1));
	if (!new->filename)
		return ;
	while (i <= new->redir_cnt)
		new->filename[i++] = NULL;
	new->redir = (char **)malloc(sizeof(char *) * (new->redir_cnt + 1));
	if (!new->redir)
	{
		free(new->filename);
		return ;
	}
	i = 0;
	while (i <= new->redir_cnt)
		new->redir[i++] = NULL;
	new->redir_flag = (int *)malloc(sizeof(int) * new->redir_cnt);
	if (!new->redir_flag)
	{
		free(new->filename);
		free(new->redir);
		return ;
	}
}

static void	set_redir_struct(t_token *token, t_redir *new, size_t k, size_t l)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (token[i].cmd)
	{
		if (flag)
		{
			new->filename[j++] = ft_strdup(token[i].cmd);
			token[i].redir_flag = REDIR_FILE;
			flag = 0;
		}
		else if (token[i].redir_flag && !flag)
		{
			new->redir[k++] = ft_strdup(token[i].cmd);
			new->redir_flag[l++] = token[i].redir_flag;
			flag = 1;
		}
		i++;
	}
}

t_redir	get_redir_struct(t_token *token)
{
	t_redir	new;

	new.redir_cnt = get_redir_cnt(token);
	if (new.redir_cnt)
	{
		malloc_redir_struct(&new);
		set_redir_struct(token, &new, 0, 0);
	}
	else
	{
		new.filename = NULL;
		new.redir = NULL;
		new.redir_flag = NULL;
	}
	return (new);
}
