/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:09:12 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 21:21:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_top_2(t_info *info, t_stack **top, long num)
{
	*top = (t_stack *)malloc(sizeof(t_stack));
	if (*top == NULL)
	{
		free_stack(info);
		free(info);
		exit(1);
	}
	(*top)->next = NULL;
	(*top)->prev = NULL;
	(*top)->num = num;
}

void	stack_add_top(t_info *info, char stack_name, long num)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
		{
			free_stack(info);
			free(info);
			exit(1);
		}
		tmp->next = *top;
		tmp->prev = NULL;
		(*top)->prev = tmp;
		tmp->num = num;
		*top = (*top)->prev;
	}
	else
		stack_add_top_2(info, top, num);
}

void	stack_add_end_2(t_info *info, t_stack **top, long num)
{
	*top = (t_stack *)malloc(sizeof(t_stack));
	if (*top == NULL)
	{
		free_stack(info);
		free(info);
		exit(1);
	}
	(*top)->next = NULL;
	(*top)->prev = NULL;
	(*top)->num = num;
}

void	stack_add_end(t_info *info, char stack_name, long num)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
		{
			free_stack(info);
			free(info);
			exit(1);
		}
		*top = listlast(*top);
		tmp->num = num;
		tmp->next = NULL;
		tmp->prev = *top;
		(*top)->next = tmp;
		*top = tmp;
	}
	else
		stack_add_end_2(info, top, num);
	*top = listfirst(*top);
}
