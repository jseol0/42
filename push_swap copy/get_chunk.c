/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:24:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/22 17:37:23 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_info *info)
{
	int tmp;
	int i;
	int j;

	i = 0;
	while (i < info->a_size - 1)
	{
		j = 0;
		while (j < info->a_size - 1 - i)
		{
			if (info->chunk[j] > info->chunk[j + 1])
			{
				tmp = info->chunk[j];
				info->chunk[j] = info->chunk[j + 1];
				info->chunk[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	get_chunk_size(t_info *info, int a_size)
{
	int size;

	size = a_size / 20;
	if (a_size % 20 > 0)
		info->remain_chunk = (a_size % 20);
	info->chunk_size = size;
}

void	get_chunk(t_info *info)
{
	t_stack *tmp;
	int i;

	if (!(info->chunk = (int *)malloc(sizeof(int) * info->a_size)))
		exit (-1);
	tmp = info->a;
	i = 0;
	while (i < info->a_size)
	{
		info->chunk[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_chunk(info);
}
