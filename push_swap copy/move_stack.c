/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:15:31 by jseol             #+#    #+#             */
/*   Updated: 2021/06/22 12:15:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_3(t_info *info)
{
	while (info->a_move_count--)
		rra(info);
	while (info->b_move_count--)
		rb(info);
	pb(info);
}

void	move_stack_2(t_info *info)
{
	int i;

	i = 0;
	if (info->a_move_count > info->b_move_count)
	{
		while (info->b_move_count--)
			rrr(info);
		while (i++ < (info->a_move_count - info->b_move_count))
			rra(info);
	}
	else
	{
		while (info->a_move_count--)
			rrr(info);
		while (i++ < (info->b_move_count - info->a_move_count))
			rrb(info);
	}
	pb(info);
}

void	move_stack_1(t_info *info)
{
	while (info->a_move_count--)
		ra(info);
	while (info->b_move_count--)
		rrb(info);
	pb(info);
}
