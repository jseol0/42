/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:45:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/21 17:34:28 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a b 비교하는 함수 구조 만들기

void	push_b_first(t_info *info, int top, int down)
{
	int i;

	i = 0;
	if (top < (a_size - down))
	{
		while (i++ < top)
			ra(info->a);
	}
	else
	{
		while (i++ < (a_size - down))
			rra(info->a);
	}
	info->b_max = info->b->num > info->b_max ? info->b->num : info->b_max;
	info->b_min = info->b->num < info->b_min ? info->b->num : info->b_min;
}

void	move_check(t_info *info, int top, int down)
{
	if (top < (a_size - down))
	{
		info->a_move = 0;
		info->a_move_count = top;
	}
	else
	{
		info->a_move = 1;
		info->a_move_count = info->a_size - down;
	}

}

void	push_b(t_info *info, int top, int down)
{
	if (info->b == NULL || listcount(info->b) == 1)
		push_b_first(info, top, down);
	int i;

	move_check(info, top, down)
	i = 0;
	if (top < (a_size - down))
	{
		while (i < top)
		{
			ra(info->a);
			i++;
		}
	}
	else
	{
		while (i < (a_size - down))
		{
			rra(info->a);
			i++;
		}
	}
}

int	find_chunk_down(t_info *info)
{
	t_stack *tmp;
	int index;
	int i;

	index = info->a_size - 1;
	tmp = info->a;
	listlast(tmp);
	while (tmp)
	{
		i = 0;
		while (i++ < size)
		{
			if (tmp->num == info->chunk[i])
				return (index);
		}
		tmp = tmp->prev;
		index--;
	}
}

int	find_chunk_top(t_info *info)
{
	t_stack *tmp;
	int index;
	int i;

	index = 0;
	tmp = info->a;
	while (tmp)
	{
		i = 0;
		while (i++ < size)
		{
			if (tmp->num == info->chunk[i])
				return (index);
		}
		tmp = tmp->next;
		index++;
	}
}

void	a_to_b(t_info *info)
{
	int top;
	int down;

	top = find_chunk_top(info);
	down = find_chunk_down(info);
	push_b(info, top, down);
}
