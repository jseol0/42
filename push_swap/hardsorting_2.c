/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsorting_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:59:59 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 16:26:49 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_info *info, int flag)
{
	if (flag == 1)
	{
		pb(info);
		sa(info);
		pa(info);
	}
	else
	{
		pa(info);
		sb(info);
		pb(info);
	}
}

void	case_2(t_info *info, int flag)
{
	if (flag == 1)
	{
		pb(info);
		sa(info);
		pa(info);
		sa(info);
	}
}

void	hardsorting_2_b(t_info *info, int a, int b, int c)
{
	if (a < b && a < c && b > c)
	{
		sb(info);
		case_1(info, 2);
	}
	else if (a < b && a > c)
		sb(info);
	else if (a > b && a < c)
	{
		case_1(info, 2);
		sb(info);
	}
	else if (a > b && a > c && b < c)
		case_1(info, 2);
	else if (a < b && a < c && b < c)
	{
		sb(info);
		case_1(info, 2);
		sb(info);
	}
}

void	hardsorting_2_a(t_info *info, int a, int b, int c)
{
	if (a < b && a < c && b > c)
		case_1(info, 1);
	else if (a < b && a > c)
	{
		case_1(info, 1);
		sa(info);
	}
	else if (a > b && a < c)
		sa(info);
	else if (a > b && a > c && b < c)
	{
		sa(info);
		case_1(info, 1);
	}
	else if (a > b && a > c && b > c)
	{
		sa(info);
		case_1(info, 1);
		sa(info);
	}
}

void	hardsorting_2(t_info *info, t_stack *stack, int size)
{
	int	a;
	int	b;
	int	c;

	a = stack->num;
	b = stack->next->num;
	if (size == 3)
		c = stack->next->next->num;
	if (stack == info->a && a > b && size == 2)
		sa(info);
	else if (stack == info->b && a < b && size == 2)
		sb(info);
	else if (stack == info->a && size == 3)
		hardsorting_2_a(info, a, b, c);
	else if (stack == info->b && size == 3)
		hardsorting_2_b(info, a, b, c);
}
