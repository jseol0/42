/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:19:55 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 17:35:27 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		compression_condition(t_stack *oper)
{
	t_stack *tmp;

	tmp = oper;
	if ((ft_strcmp(tmp->operation, "ra") == 0
			&& ft_strcmp(tmp->next->operation, "rra") == 0)
		|| (ft_strcmp(tmp->operation, "rra") == 0
			&& ft_strcmp(tmp->next->operation, "ra") == 0)
		|| (ft_strcmp(tmp->operation, "rb") == 0
			&& ft_strcmp(tmp->next->operation, "rrb") == 0)
		|| (ft_strcmp(tmp->operation, "rrb") == 0
			&& ft_strcmp(tmp->next->operation, "rb") == 0)
		||(ft_strcmp(tmp->operation, "rr") == 0
			&& ft_strcmp(tmp->next->operation, "rrr") == 0)
		|| (ft_strcmp(tmp->operation, "rrr") == 0
			&& ft_strcmp(tmp->next->operation, "rr") == 0))
		return (1);
	return (0);
}

void	compress_oper(t_stack *oper)
{
	t_stack *head;
	t_stack *del_node_1;
	t_stack *del_node_2;

	head = oper;
	while (oper->next)
	{
		del_node_1 = oper;
		del_node_2 = oper->next;
		if (compression_condition(oper))
		{
			if (oper->prev == NULL)
				oper->next->next->prev = NULL;
			else if (oper->next->next == NULL)
				oper->prev->next = NULL;
			else
			{
				oper->prev->next = oper->next->next;
				oper->next->next->prev = oper->prev;
			}
			oper = head;
			free(del_node_1);
			free(del_node_2);
		}
		oper = oper->next;
	}
	oper = head;
}
