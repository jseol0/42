/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:38:40 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 16:44:10 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_info *info)
{
	int		tmp;
	t_stack	*back;

	back = listlast(info->a);
	if (info->a)
	{
		tmp = back->num;
		stack_add_top(info, 'a', tmp);
		stack_del_end(info, 'a');
	}
	back = listlast(info->b);
	if (info->b)
	{
		tmp = back->num;
		stack_add_top(info, 'b', tmp);
		stack_del_end(info, 'b');
	}
	append_node(&info->operation, create_node("rrr"));
}
