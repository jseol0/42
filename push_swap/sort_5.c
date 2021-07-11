/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:00:34 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 21:42:04 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_3(t_info *info)
{
	int	i;
	int	count;

	count = 0;
	while (!(info->b->num < info->a->num
			&& info->b->num > listlast(info->a)->num))
	{
		ra(info);
		count++;
	}
	pa(info);
	i = 0;
	while (i++ < count)
		rra(info);
}

void	sort_5_2(t_info *info)
{
	pa(info);
	info->max = info->a->num;
	ra(info);
}

void	sort_5_1(t_info *info)
{
	pa(info);
	info->min = info->a->num;
}

void	sort_5(t_info *info)
{
	while (listcount(info->a) != 3)
		pb(info);
	sort_3(info, info->a);
	while (info->b)
	{
		if (info->b->num < info->min)
			sort_5_1(info);
		else if (info->b->num > info->max)
			sort_5_2(info);
		else
			sort_5_3(info);
	}
}
