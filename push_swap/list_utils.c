/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:14:50 by jseol             #+#    #+#             */
/*   Updated: 2021/06/29 16:32:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			listcount(t_stack *top)
{
	int		ret;
	t_stack	*tmp_top;

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

t_stack		*create_node(char *operation)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (newnode == NULL)
		return (NULL);
	newnode->operation = operation;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void		append_node(t_stack **head, t_stack *newnode)
{
	t_stack	*tail;

	if (*head == NULL)
		*head = newnode;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newnode;
		newnode->prev = tail;
	}
}
