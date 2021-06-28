/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:12:06 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 17:37:58 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->a && info->a->next)
	{
		tmp = info->a->num;
		info->a->num = info->a->next->num;
		info->a->next->num = tmp;
		append_node(&info->operation, create_node("sa"));
	}
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->b && info->b->next)
	{
		tmp = info->b->num;
		info->b->num = info->b->next->num;
		info->b->next->num = tmp;
		append_node(&info->operation, create_node("sb"));
	}
}

void	ss(t_info *info)
{
	int	tmp;

	if (info->a && info->a->next)
	{
		tmp = info->a->num;
		info->a->num = info->a->next->num;
		info->a->next->num = tmp;
	}
	if (info->b && info->b->next)
	{
		tmp = info->b->num;
		info->b->num = info->b->next->num;
		info->b->next->num = tmp;
	}
	append_node(&info->operation, create_node("ss"));
}

void	pa(t_info *info)
{
	int	tmp;

	if (info->b)
	{
		tmp = info->b->num;
		stack_del_top(info, 'b');
		stack_add_top(info, 'a', tmp);
		append_node(&info->operation, create_node("pa"));
	}
}

void	pb(t_info *info)
{
	int	tmp;

	if (info->a)
	{
		tmp = info->a->num;
		stack_del_top(info, 'a');
		stack_add_top(info, 'b', tmp);
		append_node(&info->operation, create_node("pb"));
	}
}
