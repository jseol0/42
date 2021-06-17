/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:57:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/17 19:49:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_info *info)
{
	int count;

	count = 0;
	while (listcount(info->a) != 3)
		pb(info);
	sort_3(info);
	while (info->b)
	{
		if (info->b->num < info->min)
		{
			pa(info);
			info->min = info->a->num;
		}
		else if (info->b->num > info->max)
		{
			pa(info);
			info->max = info->a->num;
			ra(info);
		}
		else
		{
			while (!(info->b->num > info->a->num && info->b->num < info->a->next->num))
			{
				ra(info);
				count++;
			}
			ra(info);
			pa(info);
			while (count--)
				rra(info);
			rra(info);
		}
	}
}

void	hardsorting(t_info *info, t_stack *top, t_stack *end)
{
	int max;
	int min;

	max = info->max;
	min = info->min;
	if (top->num == min && end->num != max)
	{
		sa(info);
		ra(info);
	}
	else if ((top->num != max && top->num != min) && end->num == max)
		sa(info);
	else if ((top->num != max && top->num != min) && end->num == min)
		rra(info);
	else if (top->num == max && end->num != min)
		ra(info);
	else if (top->num == max && end->num == min)
	{
		sa(info);
		rra(info);
	}
}

void		sort_3(t_info *info)
{
	t_stack	*top;
	t_stack	*end;
	t_stack *tmp;


	tmp = info->a;
	top = tmp;
	end = listlast(tmp);
	listfirst(tmp);
	info->max = top->num;
	info->min = top->num;
	while (top)
	{
		info->max = info->max < top->num ? top->num : info->max;
		info->min = info->min > top->num ? top->num : info->min;
		top = top->next;
	}
	top = tmp;
	hardsorting(info, top, end);
}

void	sort_remain(t_info *info, int size)
{
	if (size == 5 || size == 4)
		sort_5(info);
	else if (size == 3)
		sort_3(info);
	else if (size == 2)
	{
		if (info->a->num > info->a->next->num)
			sa(info);
	}
}
