/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:14:50 by jseol             #+#    #+#             */
/*   Updated: 2021/06/16 13:18:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		listcount(t_stack *top)
{
	int	ret;
	t_stack *tmp_top;

	tmp_top = top;
	if (top == NULL)
		return (0);
	ret = 0;
	while (tmp_top != NULL)
	{
		ret++;
		tmp_top = tmp_top->next;
	}
	return (ret);
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
