/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:57:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/16 17:12:24 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardsorting_rev(t_info *info, t_stack *top, t_stack *end)
{
	int max;
	int min;

	max = info->max;
	min = info->min;
	if (top->num == min && end->num != max)
		rb(info);
	else if ((top->num != max && top->num != min) && end->num == max)
		rrb(info);
	else if ((top->num != max && top->num != min) && end->num == min)
		sb(info);
	else if (top->num == max && end->num != min)
	{
		rrb(info);
		sb(info);
	}
	else if (top->num == min && end->num == max)
	{
		sb(info);
		rrb(info);
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

void		sort_3(t_info *info, char stack_name)
{
	t_stack	*top;
	t_stack	*end;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
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
	if (stack_name == 'a')
		hardsorting(info, top, end);
	else
		hardsorting_rev(info, top, end);
}

void	sort_remain(t_info *info, char stack_name, int size)
{
	if (size == 3)
		sort_3(info, stack_name);
	else
	{
		if (stack_name == 'a')
		{
			if (info->a->num > info->a->next->num)
				sa(info);
		}
		else
		{
			if (info->b->num < info->b->next->num)
				sb(info);
		}
	}
}
