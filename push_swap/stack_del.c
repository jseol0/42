/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:30:17 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 21:09:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_del_top(t_info *info, char stack_name)
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

void	stack_del_end(t_info *info, char stack_name)
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
