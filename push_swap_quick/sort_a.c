/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/30 23:14:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_info *info, int size)
{
	if (size <= 3)
	{
		sort_remain(info, info->b, size);
		while (size--)
			pa(info);
		return ;
	}
	int	i;
	int	pivot;

	info->rb_count = 0;
	info->pa_count = 0;
	get_array(info, info->b, size);
	pivot = info->arr[(size / 2) - 1];
	while (size--)
	{
		if (info->b->num <= pivot)
			rb(info);
		else
			pa(info);
	}
	i = 0;
	while (i++ < info->rb_count)
		rrb(info);
	a_to_b(info, info->pa_count);
	b_to_a(info, info->rb_count);
}

void	a_to_b(t_info *info, int size)
{
	if (size <= 3 && listcount(info->a) <= 3)
	{
		sort_remain(info, info->a, size);
		return ;
	}
	else if (size <= 3)
	{
		hardsorting_2(info, info->a, size);
		return ;
	}
	int	i;
	int	pivot;

	info->ra_count = 0;
	info->pb_count = 0;
	get_array(info, info->a, size);
	pivot = info->arr[(size / 2) - 1];
	while (size--)
	{
		if (info->a->num > pivot)
			ra(info);
		else
			pb(info);
	}
	i = 0;
	while (i++ < info->ra_count)
		rra(info);
	a_to_b(info, info->ra_count);
	b_to_a(info, listcount(info->b));
}

void	sort_a(t_info *info)
{
	if (info->a_size == 1)
	{
		free_stack(info);
		free(info);
		exit(0);
	}
	if (info->a_size <= 5)
		sort_remain(info, info->a, info->a_size);
	else
		a_to_b(info, info->a_size);
}
