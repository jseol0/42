/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:53:20 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:39:05 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new;
	t_list	*ret;
	void	*new_content;

	cur = lst;
	ret = 0;
	while (cur)
	{
		new_content = f(cur->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			if (del)
				ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, new);
		cur = cur->next;
	}
	return (ret);
}
