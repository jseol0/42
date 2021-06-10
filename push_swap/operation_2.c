/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:59:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/10 16:21:32 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	int	tmp;

	if (info->a)
	{
		tmp = info->a->num;
		stack_add_end(info, 'a', tmp);
		stack_del_top(info, 'a');
	}
}

void	rb(t_info *info)
{
	int	tmp;

	if (info->b)
	{
		tmp = info->b->num;
		stack_add_end(info, 'b', tmp);
		stack_del_top(info, 'b');
	}
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}

void	rra(t_info *info)
{
	int	tmp;
	t_stack *back;

	back = listlast(info->a);
	if (info->a)
	{
		tmp = back->num;
		stack_add_top(info, 'a', tmp);
		stack_del_end(info, 'a');
	}
}

void	rrb(t_info *info)
{
	int	tmp;
	t_stack *back;

	back = listlast(info->b);
	if (info->b)
	{
		tmp = back->num;
		stack_add_top(info, 'b', tmp);
		stack_del_end(info, 'b');
	}
}
