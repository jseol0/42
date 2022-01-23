/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:21:04 by elim              #+#    #+#             */
/*   Updated: 2022/01/16 02:25:55 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_size(t_token *token)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (token[i].cmd)
	{
		if (token[i].redir_flag)
			ret++;
		i++;
	}
	ret = ft_tokensize(token) - ret;
	return (ret);
}

char	**get_cmd_args(t_token *token)
{
	char	**ret;
	size_t	i;
	size_t	j;
	size_t	size;

	size = get_size(token);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (token[i].cmd)
	{
		if (!token[i].redir_flag)
			ret[j++] = ft_strdup(token[i].cmd);
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
