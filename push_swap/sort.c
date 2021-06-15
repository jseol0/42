/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/15 11:03:31 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_middle_num(t_info *info, char stack_name)
{
	int max;
	int min;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
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

void	get_pivot(t_info *info, char stack_name)
{
	int pivot;
	int mid_num;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
	pivot = tmp->num;
	while (tmp)
	{
		mid_num = info->middle - tmp->num;
		if (mid_num < 0)
			mid_num *= -1;
		pivot = (info->middle - pivot) > mid_num ? tmp->num : pivot;
		tmp = tmp->next;
	}
	info->pivot = pivot;
}

void	sort_a(t_info *info)
{
	int i;

	get_middle_num(info, 'a');
	get_pivot(info, 'a');
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
