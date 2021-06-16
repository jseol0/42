/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/16 16:38:57 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_b(t_info *info, int b_size)
{
	int	i;
	int	a_size;

	i = 0;
	if (b_size <= 3)
	{
		sort_remain(info, 'b', b_size);
		while (i++ < b_size)
			pa(info);
		return ;
	}
	get_middle_num(info, 'b');
	get_pivot(info, 'b');
	a_size = 0;
	while (i < b_size)
	{
		if (info->b->num >= info->pivot)
		{
			pa(info);
			a_size++;
		}
		else
			rb(info);
		i++;
	}
	b_size = listcount(info->b);
	listfirst(info->b);
	sort_a(info, a_size);
	sort_b(info, b_size);
}
