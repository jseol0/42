/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:30:17 by jseol             #+#    #+#             */
/*   Updated: 2021/06/27 16:50:59 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_add_top(t_info *info, char stack_name, long num)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		{
			write (2, "Error\n", 6);
			free_stack(info);
			free(info);
			exit (1);
		}
		tmp->next = *top;
		tmp->prev = NULL;
		(*top)->prev = tmp;
		tmp->num = num;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
		{
			write (2, "Error\n", 6);
			free_stack(info);
			free(info);
			exit (1);
		}
		(*top)->next = NULL;
		(*top)->prev = NULL;
		(*top)->num = num;
	}
}

void		stack_del_top(t_info *info, char stack_name)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		if ((*top)->next == NULL)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			(*top)->prev = NULL;
			free(tmp);
		}
	}
}

void		stack_add_end(t_info *info, char stack_name, long num)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		{
			write (2, "Error\n", 6);
			free_stack(info);
			free(info);
			exit (1);
		}
		*top = listlast(*top);
		tmp->num = num;
		tmp->next = NULL;
		tmp->prev = *top;
		(*top)->next = tmp;
		*top = tmp;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
		{
			write (2, "Error\n", 6);
			free_stack(info);
			free(info);
			exit (1);
		}
		(*top)->next = NULL;
		(*top)->prev = NULL;
		(*top)->num = num;
	}
	*top = listfirst(*top);
}

void		stack_del_end(t_info *info, char stack_name)
{
	t_stack	**top;
	t_stack	*tmp;

	if (stack_name == 'a')
		top = &info->a;
	else
		top = &info->b;
	if (*top)
	{
		*top = listlast(*top);
		tmp = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		free(tmp);
	}
	*top = listfirst(*top);
}
