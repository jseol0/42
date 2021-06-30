/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsorting_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:59:59 by jseol             #+#    #+#             */
/*   Updated: 2021/06/30 22:59:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_info *info)
{
	pb(info);
	sa(info);
	pa(info);
}

void	case_2(t_info *info)
{
	pb(info);
	sa(info);
	pa(info);
	sa(info);
}

void	hardsorting_2(t_info *info, t_stack *stack, int size)
{
	int a;
	int b;
	int c;

	a = stack->num;
	b = stack->next->num;
	c = stack->next->next->num;
	if (a < b && size == 2)
		sa(info);
	if (a < b && a < c && b > c)
		case_1(info);
	else if (a < b && a > c)
		case_2(info);
	else if (a > b && a < c)
		sa(info);
	else if (a > b && a > c && b < c)
	{
		sa(info);
		case_1(info);
	}
	else if (a > b && a > c && b > c)
	{
		sa(info);
		case_2(info);
	}
}
