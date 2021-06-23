/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:15:31 by jseol             #+#    #+#             */
/*   Updated: 2021/06/23 16:14:37 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_3(t_info *info)
{
	int i;

	i = 0;
	while (i++ < info->a_move_count)
		rra(info);
	i = 0;
	while (i++ < info->b_move_count)
		rb(info);
	pb(info);
}

void	move_stack_2(t_info *info)
{
	int i;

	i = 0;
	if (info->a_move_count > info->b_move_count)
	{
		while (i++ < info->b_move_count)
			rrr(info);
		i = 0;
		while (i++ < (info->a_move_count - info->b_move_count))
			rra(info);
	}
	else
	{
		while (i++ < info->a_move_count)
			rrr(info);
		i = 0;
		while (i++ < (info->b_move_count - info->a_move_count))
			rrb(info);
	}
	pb(info);
}

void	move_stack_1(t_info *info)
{
	int i;

	i = 0;
	while (i++ < info->a_move_count)
		ra(info);
		i++;
	i = 0;
	while (i++ < info->b_move_count)
		rrb(info);
	pb(info);
}
