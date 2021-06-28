/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:45:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 22:13:35 by jseol            ###   ########.fr       */
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
	if (info->b->next != NULL && info->b->num < info->b->next->num)
		sb(info);
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
	printf("5\n");
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
		printf("4\n");
		if (j == 0 || j == 1)
		{
			push_b_first(info, top, down);
			if (count == 20)
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
		if (count == 20)
		{
			top = find_chunk_top(info, i);
			down = find_chunk_down(info, i);
		}
		else
		{
			top = find_remain_top(info, i);
			down = find_remain_down(info, i);
		}
		printf("4-1\n");
		move_check(info, top, down);
		printf("4-2\n");
		move_stack(info);
		printf("4-3\n");
		info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
		info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
		j++;
	}
	// t_stack *tmp = info->b;
	// while (tmp)
	// {
	// 	printf("%ld ", tmp->num);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
}
