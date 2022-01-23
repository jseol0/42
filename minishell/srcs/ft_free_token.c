/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:19:07 by elim              #+#    #+#             */
/*   Updated: 2022/01/22 03:09:44 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_tokensize(t_token *token)
{
	size_t	i;

	i = 0;
	if (token)
	{
		while (token[i].cmd)
			i++;
	}
	return (i);
}

void	*ft_free_token(t_token *token, int size)
{
	int	i;

	i = 0;
	if (token)
	{
		while (i < size && token[i].cmd)
		{
			free(token[i].cmd);
			token[i].cmd = NULL;
			i++;
		}
		free(token);
		token = NULL;
	}
	return (NULL);
}
