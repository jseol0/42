/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:45:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/22 18:47:52 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_first(t_info *info, int top, int down)
{
	int i;

	i = 0;
	if (top < (info->a_size - down))
	{
		while (i < top)
		{
			ra(info);
			i++;
		}
	}
	else if (top > (info->a_size - down))
	{
		while (i < (info->a_size - down))
		{
			rra(info);
			i++;
		}
	}
	pb(info);
	info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
	info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
}

void	move_check(t_info *info, int top, int down)
{
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
	move_b_check_1(info);
}

void	move_stack(t_info *info)
{
	int	i;

	i = 0;
	if (info->a_move == 0 && info->b_move == 0)
	{
		if (info->a_move_count > info->b_move_count)
		{
			while (info->b_move_count--)
				rr(info);
			while (i++ < (info->a_move_count - info->b_move_count))
				ra(info);
		}
		else
		{
			while (info->a_move_count--)
				rr(info);
			while (i++ < (info->b_move_count - info->a_move_count))
				rb(info);
		}
		pb(info);
	}
	else if (info->a_move == 0 && info->b_move == 1)
		move_stack_1(info);
	else if (info->a_move == 1 && info->b_move == 1)
		move_stack_2(info);
	else if (info->a_move == 1 && info->b_move == 0)
		move_stack_3(info);
}

void	push_b(t_info *info, int top, int down, int count)
{
	int i;

	i = 0;
	while (i++ < count)
	{
		if (info->b == NULL || listcount(info->b) == 1)
		{
			push_b_first(info, top, down);
			continue;
		}
		move_check(info, top, down);
		printf("a_move : %d a_move_count : %d b_move : %d b_move_count : %d\n", info->a_move, info->a_move_count, info->b_move, info->b_move_count);
		move_stack(info);
		info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
		info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
	}
}
