/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:32:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/15 17:35:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_b(t_info *info)
{
	t_stack *top;
	t_stack *end;
	int		n_top;
	int		n_end;

	top = info->b;
	end = listlast(info->b);
	n_top = 1;
	n_end = listcount(top, end);
	get_middle_num(info, 'b');
	get_pivot(info, 'b');
	while (1)
	{
		while (top->num >= pivot)
		{
			pa;
			n_top++;
		}
		while (end->num <= pivot)
		{
			rrb;
			pa;
			n_end--;
		}
		if (n_top >= n_end)
			break;
		rrb(info);
		sb(info);
		rb(info);
		top = top->next;
		n_top++;
		end = end->prev;
	}


}
