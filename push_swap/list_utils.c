/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:14:50 by jseol             #+#    #+#             */
/*   Updated: 2021/06/15 16:55:17 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		listcount(t_stack *top, t_stack *end)
{
	int	ret;
	t_stack *tmp_top;
	t_stack *tmp_end;

	if (top == NULL)
		return (0);
	tmp_top = top;
	tmp_end = end;
	ret = 0;
	while (tmp_top != tmp_end->next)
	{
		ret++;
		tmp_top = tmp_top->next;
	}
	return (ret)
}

t_stack	*listlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*listfirst(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}
