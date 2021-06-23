/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:38:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/23 16:51:38 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_check_5(t_info *info, t_stack *tmp_b,
	t_stack *tmp_b_last)
{
	int		rb_count;
	int		rrb_count;
	t_stack	*tmp;
	t_stack	*tmp_last;

	tmp = tmp_b;
	tmp_last = tmp_b_last;
	rb_count = 0;
	rrb_count = 0;
	while (!(tmp_last->num == info->a_num_next &&
		tmp->num == info->a_num_prev))
	{
		tmp_last = tmp;
		tmp = tmp->next;
		rb_count++;
	}
	while (!(tmp_b_last->num == info->a_num_next &&
		tmp_b->num == info->a_num_prev))
	{
		tmp_b = tmp_b_last;
		tmp_b_last = tmp_b_last->prev;
		rrb_count++;
	}
	info->b_move = rb_count > rrb_count ? 0 : 1;
	info->b_move_count = rb_count > rrb_count ? rrb_count : rb_count;
}

void	move_b_check_4(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	t_stack *tmp_b_last;

	tmp_b = info->b;
	tmp_b_last = listlast(tmp_b);
	listfirst(tmp_b);
	find_b_in_chunk_1(info, a_num);
	find_b_in_chunk_2(info, a_num);
	printf("a_num : %d prev : %d next : %d\n", a_num, info->a_num_prev, info->a_num_next);
	move_b_check_5(info, tmp_b, tmp_b_last);
}

void	move_b_check_3(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	int		rb_count;
	int		rrb_count;

	tmp_b = info->b;
	rb_count = 0;
	rrb_count = 0;
	if (a_num < info->b_min)
	{
		while (tmp_b->num != info->b_min)
		{
			tmp_b = tmp_b->next;
			rb_count++;
		}
		listlast(tmp_b);
		while (tmp_b->num != info->b_min)
		{
			tmp_b = tmp_b->prev;
			rrb_count++;
		}
		info->b_move = rb_count > rrb_count ? 0 : 1;
		info->b_move_count = rb_count > rrb_count ? rrb_count : rb_count;
	}
	else if (a_num < info->b_max && a_num > info->b_min)
		move_b_check_4(info, a_num);
}

void	move_b_check_2(t_info *info, int a_num)
{
	t_stack	*tmp_b;
	int		rb_count;
	int		rrb_count;

	tmp_b = info->b;
	rb_count = 0;
	rrb_count = 0;
	if (a_num > info->b_max)
	{
		while (tmp_b->num != info->b_max)
		{
			tmp_b = tmp_b->next;
			rb_count++;
		}
		listlast(tmp_b);
		while (tmp_b->num != info->b_max)
		{
			tmp_b = tmp_b->prev;
			rrb_count++;
		}
		info->b_move = rb_count > rrb_count ? 0 : 1;
		info->b_move_count = rb_count > rrb_count ? rrb_count : rb_count;
	}
	else
		move_b_check_3(info, a_num);

}

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
