/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/16 17:36:29 by jseol            ###   ########.fr       */
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
		pivot = ft_abs(info->middle - pivot) > ft_abs(mid_num) ? tmp->num : pivot;
		tmp = tmp->next;
	}
	info->pivot = pivot;
}

void	sort_a(t_info *info, int a_size)
{
	printf("a_size : %d\n", a_size);

	if (a_size <= 3)
	{
		sort_remain(info, 'a', a_size);
		return ;
	}
	int	i;
	int	ra_count;
	int	b_size;

	get_middle_num(info, 'a');
	get_pivot(info, 'a');
	ra_count = 0;
	i = 0;
	while (i < a_size)
	{
		if (info->a->num >= info->pivot)
		{
			ra(info);
			ra_count++;
		}
		else
			pb(info);
		i++;
	}
	a_size = ra_count;
	b_size = listcount(info->b);
	sort_a(info, a_size);
//	sort_b(info, b_size);


	while (info->a)
	{
		printf("%ld ", info->a->num);
		info->a = info->a->next;
	}
	printf("\n");
	listfirst(info->a);
}
