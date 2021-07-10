/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 01:49:58 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_info *info, int size)
{
	if (size <= 3)
	{
		hardsorting_2(info, info->b, size);
		while (size--)
			pa(info);
		return ;
	}
	int	i;
	int	pivot;

	int rb_count = 0;
	int pa_count = 0;
	get_array(info, info->b, size);
	pivot = info->arr[((size - 1) / 2)];
	while (size--)
	{
		if (info->b->num <= pivot)
		{	rb(info);
			rb_count++;
		}
		else
		{	pa(info);
			pa_count++;}
	}
	free(info->arr);
	i = 0;
	while (i++ < rb_count)
		rrb(info);
	a_to_b(info, pa_count);
	b_to_a(info, rb_count);
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

	int ra_count = 0;
	int pb_count = 0;
	get_array(info, info->a, size);
	pivot = info->arr[((size - 1) / 2)];
	while (size--)
	{
		if (info->a->num > pivot)
		{	ra(info);
			ra_count++;
		}
		else
		{	pb(info);
			pb_count++;
		}
	}
	free(info->arr);
	i = 0;
	while (i++ < ra_count)
		rra(info);
	a_to_b(info, ra_count);
	b_to_a(info, pb_count);
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
