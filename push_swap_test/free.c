/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:18:13 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 17:42:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_info *info)
{
	t_stack *tmp;

	tmp = info->b;
	while (info->b)
	{
		info->b = info->b->next;
		free(tmp);
		tmp = info->b;
	}
	tmp = info->a;
	while (info->a)
	{
		info->a = info->a->next;
		free(tmp);
		tmp = info->a;
	}
	tmp = info->operation;
	while (info->operation)
	{
		info->operation = info->operation->next;
		free(tmp);
		tmp = info->operation;
	}
}

void	split_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
