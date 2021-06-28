/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 13:22:08 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_remain_down(t_info *info, int count)
{
	t_stack *tmp;
	int index;
	int i;

	index = listcount(info->a) - 1;
	tmp = info->a;
	tmp = listlast(tmp);
	while (tmp)
	{
		i = 0 + (20 * count);
		while (i < info->remain_chunk + (20 * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->prev;
		index--;
	}
	return (index);
}

int	find_remain_top(t_info *info, int count)
{
	t_stack *tmp;
	int index;
	int i;

	index = 0;
	tmp = info->a;
	while (tmp)
	{
		i = 0 + (20 * count);
		while (i < info->remain_chunk + (20 * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	find_chunk_down(t_info *info, int count)
{
	t_stack *tmp;
	int index;
	int i;

	index = listcount(info->a) - 1;
	tmp = info->a;
	tmp = listlast(tmp);
	while (tmp)
	{
		i = 0 + (20 * count);
		while (i < 20 + (20 * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->prev;
		index--;
	}
	return (index);
}

int	find_chunk_top(t_info *info, int count)
{
	t_stack *tmp;
	int index;
	int i;

	index = 0;
	tmp = info->a;
	while (tmp)
	{
		i = 0 + (20 * count);
		while (i < 20 + (20 * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void	a_to_b(t_info *info)
{
	int	top;
	int	down;
	int	i;

	i = 0;
	while (i < info->chunk_size)
	{
		top = find_chunk_top(info, i);
		down = find_chunk_down(info, i);
		push_b(info, top, down, 20, i);
		i++;
	}
	if (info->remain_chunk)
	{
		top = find_remain_top(info, i);
		down = find_remain_down(info, i);
		push_b(info, top, down, info->remain_chunk, i);
	}
}

void	sort_a(t_info *info, int a_size)
{
	if (a_size <= 5)
		sort_remain(info, a_size);
	else
	{
		get_chunk_size(info, a_size);
		get_chunk(info);
		a_to_b(info);
		while (info->b)
			pa(info);
		free(info->chunk);
	}
}
