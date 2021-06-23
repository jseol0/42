/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:28:51 by jseol             #+#    #+#             */
/*   Updated: 2021/06/23 16:52:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//다시 보기

void	find_b_in_chunk_2(t_info *info, int a_num)
{
	t_stack *tmp;
	int i;
	int pivot;

	i = 0;
	while (info->chunk[i] != a_num)
		i++;
	pivot = i;
	while (pivot < info->chunk_count - i)
	{
		pivot++;
		tmp = info->b;
		while (tmp)
		{
			if (tmp->num == info->chunk[pivot])
				break ;
			tmp = tmp->next;
		}
	}
	info->a_num_next = tmp->num;
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
				break ;
			tmp = tmp->next;
		}
	}
	info->a_num_prev = tmp->num;
}
