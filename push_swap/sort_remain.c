/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:57:59 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 01:05:56 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_info *info)
{
	int	count;
	int	i;

	while (listcount(info->a) != 3)
		pb(info);
	sort_3(info, info->a);
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
	}
}

void	hardsorting_b(t_info *info, t_stack *top, t_stack *end)
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

void	hardsorting_a(t_info *info, t_stack *top, t_stack *end)
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

void		sort_3(t_info *info, t_stack *stack)
{
	t_stack	*top;
	t_stack	*end;
	t_stack *tmp;
	tmp = stack;
	top = tmp;
	end = listlast(tmp);
	info->max = top->num;
	info->min = top->num;
	while (top)
	{
		info->max = info->max < top->num ? top->num : info->max;
		info->min = info->min > top->num ? top->num : info->min;
		top = top->next;
	}
	top = listfirst(tmp);
	if (stack == info->a)
		hardsorting_a(info, top, end);
	else
		hardsorting_b(info, top, end);
}

void	sort_remain(t_info *info, t_stack *stack, int size)
{
	if (size == 5 || size == 4)
		sort_5(info);
	else if (size == 3 && stack)
		sort_3(info, stack);
	else if (size == 2 && stack)
	{
		if (stack == info->a && stack->num > stack->next->num)
			sa(info);
		else if (stack == info->b && stack->num < stack->next->num)
			sb(info);
	}
}
