/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/17 15:46:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_info *info, int b_size)
{
	int	i;
	int	rb_count;
	int	pa_count;
	int	ra_count;

	i = 0;
	if (b_size == 1)
	{
		// sort_remain(info, 'b', b_size);
		// while (i++ < b_size)
		// 	pa(info);
		pa(info);
		return ;
	}
	get_middle_num(info, 'b');
	get_pivot(info, 'b');

	rb_count = 0;
	pa_count = 0;
	ra_count = 0;
	while (i++ < b_size)
	{
		if (info->b->num <= info->pivot_s)
		{
			rb(info);
			rb_count++;
		}
		else
		{
			pa(info);
			pa_count++;
		}
	}
	i = 0;
	while (i++ < rb_count)
		rrb(info);
	// rerocate(info, ra_count, rb_count);
	sort_a(info, pa_count);
	sort_b(info, rb_count);
}
