/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/14 19:33:49 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_middle_num(t_info *info)
{
	int max;
	int min;
	t_stack *tmp;

	tmp = info->a;
	max = tmp->num;
	min = tmp->num;
	while (tmp)
	{
		max = max < tmp->num ? tmp->num : max;
		min = min > tmp->num ? tmp->num : min;
		tmp = tmp->next;
	}
	info->middle = (max + min) / 2;
}

void	get_pivot(t_info *info)
{
	int pivot;
	int mid_num;
	t_stack *tmp;

	pivot = tmp->num;
	tmp = info->a;
	while (tmp)
	{
		mid_num = info->middle - tmp->num;
		if (mid_num < 0)
			mid_num *= -1;
		pivot = pivot > mid_num ? mid_num : pivot;
		tmp = tmp->next;
	}
	info->pivot = pivot;
}

void	sort(t_info *info)
{
	int i;

	get_middle_num(info);
	get_pivot(info);
	i = 0;
	while (info->a_size)
	{
		if (info->a->num > info->pivot)
			ra(info);
		else
			pb(info);
	}
	// b에서 a로 넘기기....
}
