/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:45:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/29 16:36:46 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_first(t_info *info, int top, int down)
{
	int i;

	i = 0;
	if (top <= (info->a_size - down))
	{
		while (i < top)
		{
			ra(info);
			i++;
		}
	}
	else
	{
		while (i < (info->a_size - down))
		{
			rra(info);
			i++;
		}
	}
	pb(info);
	info->a_size = listcount(info->a);
	info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
	info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
	if (info->b->next != NULL && info->b->num < info->b->next->num)
		sb(info);
}

void	move_check(t_info *info, int top, int down)
{
	info->a_size = listcount(info->a);
	if (top <= (info->a_size - down))
	{
		info->a_move = 0;
		info->a_move_count = top;
	}
	else
	{
		info->a_move = 1;
		info->a_move_count = info->a_size - down;
	}
	if (info->a_size == 1)
		info->a_move_count = 0;
	move_b_check_1(info);
}

void	move_stack(t_info *info)
{
	if (info->a_move == 0 && info->b_move == 0)
		move_stack_0(info);
	else if (info->a_move == 0 && info->b_move == 1)
		move_stack_1(info);
	else if (info->a_move == 1 && info->b_move == 1)
		move_stack_2(info);
	else if (info->a_move == 1 && info->b_move == 0)
		move_stack_3(info);
	info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
	info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
	if (info->b_after_move == 1)
		rb(info);
	else if (info->b_after_move == 2)
		b_after_move(info);
}

void	push_b(t_info *info, int top, int down, int count, int i)
{
	int j;

	j = 0;
	while (j < count)
	{
		if (info->b == NULL || info->b->next == NULL)
		{
			push_b_first(info, top, down);
			if (count == info->chunk_count)
			{
				top = find_chunk_top(info, i);
				down = find_chunk_down(info, i);
			}
			else
			{
				top = find_remain_top(info, i);
				down = find_remain_down(info, i);
			}
			j++;
			continue;
		}
		if (count == info->chunk_count)
		{
			top = find_chunk_top(info, i);
			down = find_chunk_down(info, i);
		}
		else
		{
			top = find_remain_top(info, i);
			down = find_remain_down(info, i);
		}
		move_check(info, top, down);
		move_stack(info);
		info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
		info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
		j++;
	}
}
