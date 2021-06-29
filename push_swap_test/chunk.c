/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:24:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/29 10:54:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_b_in_chunk_2(t_info *info, int a_num)
{
	t_stack *tmp;
	int i;
	int pivot;

	i = 0;
	while (info->chunk[i] != a_num)
		i++;
	pivot = i;
	while (pivot < info->first_a_size)
	{
		pivot++;
		tmp = info->b;
		while (tmp)
		{
			if (tmp->num == info->chunk[pivot])
			{
				info->a_num_next = tmp->num;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	find_b_in_chunk_1(t_info *info, int a_num)
{
	t_stack *tmp;
	int i;
	int pivot;

	i = 0;
	while (info->chunk[i] != a_num)
		i++;
	pivot = i;
	while (pivot > -1)
	{
		pivot--;
		tmp = info->b;
		while (tmp)
		{
			if (tmp->num == info->chunk[pivot])
			{
				info->a_num_prev = tmp->num;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	sort_chunk(t_info *info)
{
	int tmp;
	int i;
	int j;

	i = 0;
	while (i < info->first_a_size - 1)
	{
		j = 0;
		while (j < info->first_a_size - 1 - i)
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

	if (!(info->chunk = (int *)malloc(sizeof(int) * info->first_a_size)))
	{
		free_stack(info);
		free(info);
		exit (1);
	}
	tmp = info->a;
	i = 0;
	while (i < info->first_a_size)
	{
		info->chunk[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_chunk(info);
}
