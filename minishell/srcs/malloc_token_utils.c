/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_token_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:17:22 by elim              #+#    #+#             */
/*   Updated: 2022/01/15 21:18:30 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	case_redir(char *line)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
			size++;
		else
			break ;
		i++;
	}
	return (size);
}
