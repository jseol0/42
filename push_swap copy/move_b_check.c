/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:38:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/22 18:51:16 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_check_5(t_info *info, t_stack *tmp_b,
	t_stack *tmp_b_last, int a_num)
{
	int		ra_count;
	int		rra_count;

	ra_count = 0;
	rra_count = 0;
	while (!(tmp_b_last->num > a_num &&
		tmp_b->num < a_num))
	{
		tmp_b = tmp_b->next;
		ra_count++;
	}
	listlast(tmp_b);
	while (!(tmp_b_last->num > a_num &&
		tmp_b->num < a_num))
	{
		tmp_b = tmp_b->prev;
		rra_count++;
	}
	info->b_move = ra_count > rra_count ? 0 : 1;
	info->b_move_count = ra_count > rra_count ? rra_count : ra_count;

}

void	move_b_check_4(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	t_stack *tmp_b_last;

	tmp_b = info->b;
	tmp_b_last = listlast(tmp_b);
	listfirst(tmp_b);
	move_b_check_5(info, tmp_b, tmp_b_last, a_num);
}

void	move_b_check_3(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	int		ra_count;
	int		rra_count;

	tmp_b = info->b;
	ra_count = 0;
	rra_count = 0;
	if (a_num < info->b_min)
	{
		while (tmp_b->num != info->b_min)
		{
			tmp_b = tmp_b->next;
			ra_count++;
		}
		listlast(tmp_b);
		while (tmp_b->num != info->b_min)
		{
			tmp_b = tmp_b->prev;
			rra_count++;
		}
		info->b_move = ra_count > rra_count ? 0 : 1;
		info->b_move_count = ra_count > rra_count ? rra_count : ra_count;
	}
	else if (a_num < info->b_max && a_num > info->b_min)
		move_b_check_4(info, a_num);
}

void	move_b_check_2(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	int		ra_count;
	int		rra_count;

	tmp_b = info->b;
	ra_count = 0;
	rra_count = 0;
	printf("%d %d", a_num, info->b_max);
	if (a_num > info->b_max)
	{
		while (tmp_b->num != info->b_max)
		{
			tmp_b = tmp_b->next;
			ra_count++;
		}
		listlast(tmp_b);
		while (tmp_b->num != info->b_max)
		{
			tmp_b = tmp_b->prev;
			rra_count++;
		}
		info->b_move = ra_count > rra_count ? 0 : 1;
		info->b_move_count = ra_count > rra_count ? rra_count : ra_count;
	}
	else
			move_b_check_3(info, a_num);
}

//move_count 체크하기

void	move_b_check_1(t_info *info)
{
	t_stack *tmp_a;
	int		a_num;
	int		i;

	a_num = 0;
	tmp_a = info->a;
	i = 0;
	if (info->a_move == 0)
	{
		while (i++ < info->a_move_count)
			tmp_a = tmp_a->next;
		a_num = tmp_a->num;
	}
	else
	{
		while (i++ < info->a_move_count)
			tmp_a = tmp_a->prev;
		a_num = tmp_a->num;
	}
	move_b_check_2(info, a_num);
}
